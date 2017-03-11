import QtQuick 2.5

Item {
    id: root
    
    property var colors: ["red", "white", "blue"]

    width: 640; height: 480

    ListView {
        id: _listView
        anchors.fill: parent

        model: root.colors
        delegate: Rectangle {
            id: _rectangleDelegate
            width: ListView.view.width
            height: ListView.view.height / 3
            
            color: model.modelData
        }
    }
}