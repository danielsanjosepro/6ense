//
//  SafetyScore.swift
//  sixsense
//
//  Created by Alexander Behl on 26.06.21.
//

import Foundation
import MapKit


struct SafetyScore {
    let latitude: Double
    let longitude: Double
    var coordinate: CLLocationCoordinate2D {
        CLLocationCoordinate2D(latitude: latitude, longitude: longitude)
    }
    var totalScore: Double
    var speedScore: Double
    var distanceScore: Double
    var brakeScore: Double
}


