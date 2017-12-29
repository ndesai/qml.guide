import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480


    MusicTrackModel {
        id: _musicTrackModel

        MusicTrack {
            title: "The first track"
            artistName: "John Doe"
            duration: 230213
        }
        MusicTrack {
            title: "The second track"
            artistName: "John Doe"
            duration: 123111
        }
        MusicTrack {
            title: "The third track"
            artistName: "John Doe"
            duration: 12239991
        }
    }

    ListView {
        anchors.fill: parent
        model: _musicTrackModel
        delegate: Item {
            width: ListView.view.width
            height: 40

            Text {
                anchors.centerIn: parent
                font.bold: true
                // NOTE: This is where the roleName comes into play
                // There is a magic object called "dataObject" that references the
                // MusicTrack object for this particular index
                text: dataObject.title + " by " + dataObject.artistName
            }
        }
    }
}
