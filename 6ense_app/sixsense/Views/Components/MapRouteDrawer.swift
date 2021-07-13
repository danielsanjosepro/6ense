//
//  MapRouteDrawer.swift
//  sixsense
//
//  Created by Alexander Behl on 26.06.21.
//

import Foundation
import MapKit

class GradientPolyline: MKPolyline {
    var hues: [CGFloat]?
    public func getHue(from index: Int) -> CGColor {
        return UIColor(hue: (hues?[index])!, saturation: 1, brightness: 1, alpha: 1).cgColor
    }
}

extension GradientPolyline {
    convenience init(scores: [SafetyScore]) {
        let coordinates = scores.map( { $0.coordinate } )
        self.init(coordinates: coordinates, count: coordinates.count)
        let S_MAX: Double = 100.0, S_MIN = 0.0, H_MAX = 0.3, H_MIN = 0.03
       hues = scores.map({
        let score: Double = Double($0.totalScore)

           if score > S_MAX {
               return CGFloat(H_MAX)
           }

           if S_MIN <= score || score <= S_MAX {
               return CGFloat((H_MIN + ((score - S_MIN) * (S_MAX - S_MIN)) / (S_MAX - S_MIN)))
           }

           if score < S_MIN {
               return CGFloat(H_MIN)
           }

           return CGFloat(score)
       })
    }
}

class GradidentPolylineRenderer: MKPolylineRenderer {

    override func draw(_ mapRect: MKMapRect, zoomScale: MKZoomScale, in context: CGContext) {
        let boundingBox = self.path.boundingBox
        let mapRectCG = rect(for: mapRect)

        if(!mapRectCG.intersects(boundingBox)) { return }

        var prevColor: CGColor?
        var currentColor: CGColor?

        guard let polyLine = self.polyline as? GradientPolyline else { return }

        for index in 0...self.polyline.pointCount - 1{
            let point = self.point(for: self.polyline.points()[index])
            let path = CGMutablePath()
            currentColor = polyLine.getHue(from: index)
            if index == 0 {
               path.move(to: point)
            } else {
                let prevPoint = self.point(for: self.polyline.points()[index - 1])
                path.move(to: prevPoint)
                path.addLine(to: point)

                let colors = [prevColor!, currentColor!] as CFArray
                let baseWidth = self.lineWidth / zoomScale

                context.saveGState()
                context.addPath(path)

                let gradient = CGGradient(colorsSpace: nil, colors: colors, locations: [0, 1])
                context.setLineWidth(baseWidth)
                context.replacePathWithStrokedPath()
                context.clip()
                context.drawLinearGradient(gradient!, start: prevPoint, end: point, options: [])
                context.restoreGState()
            }
            prevColor = currentColor
        }
    }
}
