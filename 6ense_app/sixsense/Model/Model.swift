//
//  Model.swift
//  sixsense
//
//  Created by Alexander Behl on 26.06.21.
//

import Foundation
import CoreLocation

class Model: ObservableObject{
    @Published var scores: [SafetyScore]
    @Published var incidents: [SafetyIncident]
    @Published var newIncident: Bool
    private var locationManager: LocationManager
   
    var lastLocation: CLLocationCoordinate2D {
        get {
            if let last = locationManager.lastLocation {
                return CLLocationCoordinate2D(latitude: last.coordinate.latitude, longitude: last.coordinate.longitude)
            }
            return CLLocationCoordinate2D(latitude: 48.19259059091682, longitude: 11.642832739216752)
        }
    }

    init() {
        self.scores = []
        self.incidents = []
        self.newIncident = false
        self.locationManager = LocationManager()
    }
    
    func addSafetyData(totalScore: Double, speedScore: Double, distanceScore: Double, brakeScore: Double) {
        if let location = locationManager.lastLocation {
            self.scores.append(SafetyScore(latitude: location.coordinate.latitude, longitude: location.coordinate.longitude, totalScore: totalScore, speedScore: speedScore, distanceScore: distanceScore, brakeScore: brakeScore))
            
            let scoreRates: [(IncidentType, Int)] = [(IncidentType.speed, self.getLiveSpeedScoreRate()), (IncidentType.distance, self.getLiveDistanceScoreRate()), (IncidentType.brake, self.getLiveBrakeScoreRate())]
            if getLiveTotalScoreRate() != 100 {
                let incident = scoreRates.reduce((IncidentType.speed, 100), { final, new in
                    if new.1 < final.1 {
                        return new
                    }
                    return final
                }).0
                self.incidents.append(SafetyIncident(latitude: location.coordinate.latitude, longitude: location.coordinate.longitude, incident: incident))
                self.newIncident = true
            } else {
                self.newIncident = false
            }
        }
    }
    
    func getLiveTotalScoreRate() -> Int {
        if let score = scores.last, scores.count > 2 {
            let previousScore = scores[scores.count - 2]
            let scoreDecrease = previousScore.totalScore - score.totalScore
            if scoreDecrease < 0 {
                return 100
            } else if scoreDecrease > 1 {
                return 0
            }
            return 100 - Int(scoreDecrease * 100)
        }
        return 100
    }
    
    func getLiveSpeedScoreRate() -> Int {
        if let score = scores.last, scores.count > 2 {
            let previousScore = scores[scores.count - 2]
            let scoreDecrease = previousScore.speedScore - score.speedScore
            if scoreDecrease < 0 {
                return 100
            } else if scoreDecrease > 1 {
                return 0
            }
            return 100 - Int(scoreDecrease * 100)
        }
        return 100
    }
    
    func getLiveDistanceScoreRate() -> Int {
        if let score = scores.last, scores.count > 2 {
            let previousScore = scores[scores.count - 2]
            let scoreDecrease = previousScore.distanceScore - score.distanceScore
            if scoreDecrease < 0 {
                return 100
            } else if scoreDecrease > 1 {
                return 0
            }
            return 100 - Int(scoreDecrease * 100)
        }
        return 100
    }
    
    func getLiveBrakeScoreRate() -> Int {
        if let score = scores.last, scores.count > 2 {
            let previousScore = scores[scores.count - 2]
            let scoreDecrease = previousScore.brakeScore - score.brakeScore
            if scoreDecrease < 0 {
                return 100
            } else if scoreDecrease > 1 {
                return 0
            }
            return 100 - Int(scoreDecrease * 100)
        }
        return 100
    }
    
    func getTotalScore() -> Int {
        var score = 100.00
        if let last = scores.last {
            score = last.totalScore
        }
        return Int(score)
    }
    
    func getSpeedScore() -> Int {
        var score = 100.00
        if let last = scores.last {
            score = last.speedScore
        }
        return Int(score)
    }
    
    func getDistanceScore() -> Int {
        var score = 100.00
        if let last = scores.last {
            score = last.distanceScore
        }
        return Int(score)
    }
    
    func getBrakeScore() -> Int {
        var score = 100.00
        if let last = scores.last {
            score = last.brakeScore
        }
        return Int(score)
    }
}
