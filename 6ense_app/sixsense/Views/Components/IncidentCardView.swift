//
//  IncidentCardView.swift
//  sixsense
//
//  Created by Alexander Behl on 26.06.21.
//

import SwiftUI

struct IncidentCardView: View {
    var incidentType: IncidentType
    
    var body: some View {
        VStack {
            ZStack {
                RoundedRectangle(cornerRadius: 14).frame(height: 90).foregroundColor(.white)
                    .shadow(color: .gray, radius: 10, x: 0.0, y: 0.0)
                HStack {
                    if incidentType == IncidentType.distance {
                        Image(systemName: "figure.stand.line.dotted.figure.stand")
                            .resizable()
                            .frame(width: 60, height: 40)
                            .foregroundColor(.red)
                            .padding(.trailing, 14)
                    } else if incidentType == IncidentType.speed {
                        Image(systemName: "hare.fill")
                            .resizable()
                            .frame(width: 60, height: 40)
                            .foregroundColor(.red)
                            .padding(.trailing, 14)
                    } else {
                        Image(systemName: "hand.raised.slash.fill")
                            .resizable()
                            .frame(width: 40, height: 40)
                            .foregroundColor(.red)
                            .padding(.trailing, 14)
                    }
                    Spacer()
                    VStack {
                        HStack {
                            if incidentType == IncidentType.distance {
                                Text("Distance Warning").font(.headline)
                            } else if incidentType == IncidentType.speed {
                                Text("Speed Warning").font(.headline)
                            } else {
                                Text("Brake Warning").font(.headline)
                            }
                            Spacer()
                        }
                        HStack {
                            if incidentType == IncidentType.distance {
                                Text("Keep a distance of at least 1.5 meters").font(.subheadline)
                            } else if incidentType == IncidentType.speed {
                                Text("Don't go over 30 km/h").font(.subheadline)
                            } else {
                                Text("Avoid sudden braking behavior").font(.subheadline)
                            }
                            Spacer()
                        }
                    }
                }.padding(22)
            }
            .padding()
        }
        Spacer()
    }
}

