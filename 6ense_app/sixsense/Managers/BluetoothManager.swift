//
//  BluetoothManager.swift
//  sixsense
//
//  Created by Alexander Behl on 26.06.21.
//

import Foundation
import CoreBluetooth
import SwiftUI

class BLEManager: NSObject, ObservableObject, CBCentralManagerDelegate {
     
    @Published var connected = false
    @Published var duringScan = false
    var myCentral: CBCentralManager!
    var selectedPeripheral: CBPeripheral?
    var peripherals = [CBPeripheral]()
    var timers: [Timer] = []
    var selectedCharacteristics: [CBCharacteristic]?
    @ObservedObject var model: Model
    
        init(model: Model) {
            self.model = model
            super.init()
            myCentral = CBCentralManager(delegate: self, queue: nil)
            myCentral.delegate = self
        }

    func centralManagerDidUpdateState(_ central: CBCentralManager) {
        
    }
    
    func centralManager(_ central:  CBCentralManager, didConnect peripheral: CBPeripheral) {
        connected = true
        selectedPeripheral = peripheral
        peripheral.discoverServices(nil)
    }
    
    func centralManager(_ central: CBCentralManager, didDisconnectPeripheral peripheral: CBPeripheral, error: Error?) {
        connected = false
        selectedPeripheral = nil
        timers.forEach{ $0.invalidate() }
    }

    func centralManager(_ central: CBCentralManager, didDiscover peripheral: CBPeripheral, advertisementData: [String : Any], rssi RSSI: NSNumber) {
        if !peripherals.contains(peripheral) && peripheral.name == "Nano33BLE" || peripheral.name == "Arduino" {
            peripherals.append(peripheral)
            peripheral.delegate = self
        }
    }
    
    func changeConnection() {
        if let realSelectedPeripheral = selectedPeripheral {
            timers.forEach{ $0.invalidate() }
            myCentral.cancelPeripheralConnection(realSelectedPeripheral)
        } else {
            startScan()
            model.scores = []
            model.incidents = []
        }
    }
    
    func startScan() {
        myCentral.scanForPeripherals(withServices: nil, options: [CBCentralManagerScanOptionAllowDuplicatesKey: false])
        duringScan = true
        Timer.scheduledTimer(timeInterval: 2, target: self, selector: #selector(self.stopScan), userInfo: nil, repeats: false)
    }
    
    @objc func stopScan() {
        myCentral.stopScan()
        duringScan = false
        let initPeripheral: CBPeripheral? = nil
        let peripheral = peripherals.reduce(initPeripheral) { finalPeripheral, currentPeripheral in
            if let realFinalPeripheral = finalPeripheral, realFinalPeripheral.readRSSI() > currentPeripheral.readRSSI() {
                    return finalPeripheral
            }
            return currentPeripheral
        }
        if let realPeripheral = peripheral {
            myCentral.connect(realPeripheral, options: nil)
        }
    }
}

extension BLEManager: CBPeripheralDelegate {
    
    func peripheral(_ peripheral: CBPeripheral, didUpdateValueFor characteristic: CBCharacteristic, error: Error?) {
        let dataString = String(decoding: characteristic.value!, as: UTF8.self)
        let dataArray = dataString.components(separatedBy: ",")
        if dataArray.count == 4 {
            let totalScore = Double(dataArray[0]) ?? 100.00
            let speedScore = Double(dataArray[1]) ?? 100.00
            let distanceScore = Double(dataArray[2]) ?? 100.00
            let brakeScore = Double(dataArray[3]) ?? 100.00
            model.addSafetyData(totalScore: totalScore, speedScore: speedScore, distanceScore: distanceScore, brakeScore: brakeScore)
        }
    }
    
    func peripheral(_ peripheral: CBPeripheral, didDiscoverServices error: Error?) {
        guard let services = peripheral.services else { return }
        for service in services {
            peripheral.discoverCharacteristics(nil, for: service)
        }
    }
    
    func peripheral(_ peripheral: CBPeripheral, didDiscoverCharacteristicsFor service: CBService,
                    error: Error?) {
      guard let characteristics = service.characteristics else { return }
        selectedCharacteristics =  characteristics
        timers.append(Timer.scheduledTimer(timeInterval: 1, target: self, selector: #selector(fireTimer), userInfo: nil, repeats: true))
    }
    
    @objc func fireTimer() {
        if let realSelectedPeripheral = selectedPeripheral, let realSelectedCharacteristics = selectedCharacteristics {
            for characteristic in realSelectedCharacteristics {
                realSelectedPeripheral.readValue(for: characteristic)
            }
        }
    }
}

