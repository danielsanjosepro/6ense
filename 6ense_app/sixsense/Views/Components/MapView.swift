//
//  MapView.swift
//  sixsense
//
//  Created by Alexander Behl on 26.06.21.
//

import Foundation
import MapKit
import SwiftUI

struct MapView: UIViewRepresentable {
    @Binding var showIncident: Bool
    @Binding var incidentType: IncidentType
    @ObservedObject var model: Model
    var mapView = MKMapView()
    

  func makeUIView(context: Context) -> MKMapView {
    mapView.delegate = context.coordinator
    mapView.isRotateEnabled = true
    mapView.camera.heading = 90
    mapView.camera.centerCoordinate = model.lastLocation
    mapView.camera.centerCoordinateDistance = 1000
    mapView.setCamera(mapView.camera, animated: false)
    
    if self.model.scores.count > 1 {
        let polyline = GradientPolyline(scores: self.model.scores)
        mapView.addOverlay(polyline)
    }
    self.model.incidents.forEach { incident in
        let addAnotation = MKPointAnnotation()
        addAnotation.coordinate = CLLocationCoordinate2D(latitude: incident.latitude, longitude: incident.longitude)
        mapView.addAnnotation(addAnotation)
    }
    return mapView
  }

  func updateUIView(_ view: MKMapView, context: Context) {
    self.mapView.centerCoordinate = model.lastLocation
    if self.model.scores.count > 1 {
        let polyline = GradientPolyline(scores: self.model.scores)
            view.addOverlay(polyline)
    }
    self.model.incidents.forEach { incident in
        let addAnotation = MKPointAnnotation()
        addAnotation.coordinate = CLLocationCoordinate2D(latitude: incident.latitude, longitude: incident.longitude)
        view.addAnnotation(addAnotation)
    }
  }

  func makeCoordinator() -> Coordinator {
    Coordinator(self, $showIncident, $incidentType, model)
  }
}

class Coordinator: NSObject, MKMapViewDelegate {
    @Binding var showIncident: Bool
    @Binding var incidentType: IncidentType
    @ObservedObject var model: Model
    var parent: MapView

    init(_ parent: MapView, _ showIncident: Binding<Bool>, _ incidentType: Binding<IncidentType>, _ model: Model) {
        self.parent = parent
        self._incidentType = incidentType
        self._showIncident = showIncident
        self.model = model
    }
    
    func mapView(_ mapView: MKMapView, rendererFor overlay: MKOverlay) -> MKOverlayRenderer {
        if overlay is GradientPolyline {
               let polyLineRender = GradidentPolylineRenderer(overlay: overlay)
               polyLineRender.lineWidth = 10
            return polyLineRender
           }
        return MKOverlayRenderer()
    }
    
    func mapView(_ mapView: MKMapView, viewFor annotation: MKAnnotation) -> MKAnnotationView? {
            let identifier = "incident"
            var view: MKMarkerAnnotationView
            if let dequeuedView = mapView.dequeueReusableAnnotationView(
              withIdentifier: identifier) as? MKMarkerAnnotationView {
              dequeuedView.annotation = annotation
              view = dequeuedView
            } else {
              view = MKMarkerAnnotationView(
                annotation: annotation,
                reuseIdentifier: identifier)
              view.canShowCallout = true
              view.calloutOffset = CGPoint(x: -5, y: 5)
              view.rightCalloutAccessoryView = UIButton(type: .detailDisclosure)
            
            }
            return view
    }
    
    func mapView(_ mapView: MKMapView, didSelect view: MKAnnotationView) {
        if let tappedIncident = self.model.incidents.first(where: { $0.latitude == view.annotation?.coordinate.latitude && $0.longitude == view.annotation?.coordinate.longitude }) {
            self.incidentType = tappedIncident.incident
        }
        showIncident = true
    }
    func mapView(_ mapView: MKMapView, didDeselect view: MKAnnotationView) {
        showIncident = false
    }
}
