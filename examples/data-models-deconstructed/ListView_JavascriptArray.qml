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
            
            // Use the colors array to change
            // the color of this Rectangle
            color: model.modelData

            // Many times developers misuse
            // model views by accessing the array
            // directly, i.e.
            // color: root.colors[model.index]
            // or
            // color: root.colors[index]
        }
    }
}