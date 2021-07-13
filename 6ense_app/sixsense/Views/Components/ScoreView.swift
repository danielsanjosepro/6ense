//
//  ScoreView.swift
//  sixsense
//
//  Created by Alexander Behl on 26.06.21.
//

import SwiftUI

struct ScoreView: View {
    @EnvironmentObject var model: Model
    
    var body: some View {
        ZStack {
            Rectangle()
                .frame(minWidth: 0, maxWidth: .infinity, minHeight: 0, maxHeight: 110, alignment: .center)
                .foregroundColor(Color(red: 23, green: 24, blue: 21))
            HStack {
                VStack{
                    ZStack {
                        Text("\(Int(model.scores.last?.totalScore ?? 100))").bold()
                        Circle()
                            .stroke(getColor((Int(model.scores.last?.totalScore ?? 100))), lineWidth: 8)
                    }.frame(maxWidth: 56, maxHeight: 56)
                    Text("Total").font(.caption)
                }.padding(7)
                VStack{
                    ZStack {
                        Text("\(Int(model.scores.last?.speedScore ?? 100))").bold()
                        Circle()
                            .stroke(getColor((Int(model.scores.last?.speedScore ?? 100))), lineWidth: 8)
                    }.frame(maxWidth: 56, maxHeight: 56)
                    Text("Speed").font(.caption)
                }.padding(7)
                VStack{
                    ZStack {
                        Text("\(Int(model.scores.last?.distanceScore ?? 100))").bold()
                        Circle()
                            .stroke(getColor((Int(model.scores.last?.distanceScore ?? 100))), lineWidth: 8)
                    }.frame(maxWidth: 56, maxHeight: 56)
                    Text("Distance").font(.caption)
                }.padding(7)
                VStack{
                    ZStack {
                        Text("\(Int(model.scores.last?.brakeScore ?? 100))").bold()
                        Circle()
                            .stroke(getColor((Int(model.scores.last?.brakeScore ?? 100))), lineWidth: 8)
                    }.frame(maxWidth: 56, maxHeight: 56)
                    Text("Braking").font(.caption)
                }.padding(7)
            }
        }
    }
    
    
    func getColor(_ score: Int) -> Color {
        if score < 25 {
            return .red
        } else if score < 50 {
            return .orange
        } else if score < 75 {
            return .yellow
        }
        return .green
    }
}

