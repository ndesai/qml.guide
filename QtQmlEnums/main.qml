import QtQuick 2.9
import QtQuick.Window 2.2

import qml.guide 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Component.onCompleted: {
        console.log(Status.Ready);
    }
}
