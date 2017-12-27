import QtQuick 2.9
import QtQuick.Window 2.2

import QmlGuide 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Text {
        anchors.centerIn: parent
        font.pixelSize: 42
        font.family: Theme.fontFamily

        text: "Hello World"
    }
}
