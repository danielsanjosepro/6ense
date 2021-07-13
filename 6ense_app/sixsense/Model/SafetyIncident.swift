//
//  SafetyIncident.swift
//  sixsense
//
//  Created by Alexander Behl on 26.06.21.
//

import Foundation
import MapKit

enum IncidentType {
    case brake, speed, distance
}

struct SafetyIncident {
    let latitude: Double
    let longitude: Double
    var coordinate: CLLocationCoordinate2D {
        CLLocationCoordinate2D(latitude: latitude, longitude: longitude)
    }
    var incident: IncidentType
    
}
