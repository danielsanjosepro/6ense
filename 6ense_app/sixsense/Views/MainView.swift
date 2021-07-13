//
//  ContentView.swift
//  sixsense
//
//  Created by Alexander Behl on 26.06.21.
//

import SwiftUI

struct MainView: View {
    @EnvironmentObject var model: Model
    @ObservedObject var bleManager: BLEManager
    @State var showIncident = false
    @State var incidentType = IncidentType.speed
 
    init(_ model: Model) {
        self.bleManager = BLEManager(model: model)
    }
    var body: some View {
        ZStack {
            MapView(showIncident: $showIncident, incidentType: $incidentType, model: model)
                .edgesIgnoringSafeArea(.bottom)
            VStack {
                ScoreView()
                    .environmentObject(model)
                if model.newIncident {
                    IncidentCardView(incidentType: model.incidents.last?.incident ?? incidentType)
                } else if showIncident {
                    IncidentCardView(incidentType: incidentType)
                }
                Spacer()
                RideButtonView(bleManager: bleManager)
            }
        }
    }
}
