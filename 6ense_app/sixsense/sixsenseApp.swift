//
//  sixsenseApp.swift
//  sixsense
//
//  Created by Alexander Behl on 26.06.21.
//

import SwiftUI

@main
struct sixsenseApp: App {
    @StateObject var model = Model()
    var body: some Scene {
        WindowGroup {
            MainView(model).environmentObject(model)
        }
    }
}
