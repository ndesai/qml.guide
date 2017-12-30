import QtQuick 2.7

Item {
	id: root

	property real value: 5.0
	property real minimumValue: 0.0
	property real maximumValue: 10.0

	width: 200
    height: 40

    BaseObject {
        id: internal

        readonly property int scrubberXPosition: _rectangleTrack.width * (root.value / (root.maximumValue - root.minimumValue))

        Connections {
        	target: _rectangleScrubber
	        onXChanged: {
	            root.value = (x / _rectangleTrack.width) * (root.maximumValue - root.minimumValue)
	        }
    	}
    }

    Rectangle {
        id: _rectangleTrack
        anchors.centerIn: parent
        width: parent.width - _rectangleScrubber.width
        height: 4
        color: "#222222"
    }

    Rectangle {
    	id: _rectangleScrubber
    	anchors.verticalCenter: _rectangleTrack.verticalCenter

    	x: internal.scrubberXPosition

    	width: parent.height / 2
    	height: width
    	radius: width / 2

    	color: "#EEEEEE"

    	border.color: "#DDDDDD"
    	border.width: 2
    	
    	MouseArea {
    		anchors.fill: parent
    		drag.target: parent
    		drag.minimumX: 0
    		drag.maximumX: _rectangleTrack.width
    	}
    }
}
