//
//  RideButtonView.swift
//  sixsense
//
//  Created by Alexander Behl on 26.06.21.
//

import SwiftUI

struct RideButtonView: View {
    @ObservedObject var bleManager: BLEManager
    
    var body: some View {
        Button(action: {
            bleManager.changeConnection()
        }) {
            ZStack {
                RoundedRectangle(cornerRadius: 10)
                    .shadow(radius: /*@START_MENU_TOKEN@*/10/*@END_MENU_TOKEN@*/)
                HStack {
                    if bleManager.duringScan {
                        Image(systemName: "hourglass")
                            .foregroundColor(.white)
                            .padding()
                        Spacer()
                        Text("Connecting to 6ense device").fontWeight(/*@START_MENU_TOKEN@*/.bold/*@END_MENU_TOKEN@*/)
                            .foregroundColor(.white)
                        Spacer()
                        Spacer()
                    }
                    else if bleManager.connected {
                        Image(systemName: "bicycle")
                            .foregroundColor(.white)
                            .padding()
                        Spacer()
                        Text("Stop your ride").fontWeight(/*@START_MENU_TOKEN@*/.bold/*@END_MENU_TOKEN@*/)
                            .foregroundColor(.white)
                        Spacer()
                        Spacer()
                    } else {
                        Image(systemName: "bicycle")
                            .foregroundColor(.white)
                            .padding()
                        Spacer()
                        Text("Start your ride").fontWeight(/*@START_MENU_TOKEN@*/.bold/*@END_MENU_TOKEN@*/)
                            .foregroundColor(.white)
                        Spacer()
                        Spacer()
                    }
                }
            }
        }.frame(width: 330, height: 70)
        .accentColor(bleManager.connected ? .red : .green)
        .disabled(bleManager.duringScan)
    }
}
