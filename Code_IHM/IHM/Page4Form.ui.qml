import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    Text {
        id: element
        x: 171
        y: 43
        width: 259
        height: 43
        text: qsTr("Parametre réseau")
        font.wordSpacing: 0.4
        font.capitalization: Font.MixedCase
        font.weight: Font.Normal
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 24
    }

    Button {
        id: button
        x: 482
        y: 349
        text: qsTr("Suivant")
    }

    Frame {
        id: frameidentif
        x: 164
        y: 120
        width: 287
        height: 40
    }

    TextInput {
        id: identif
        x: 164
        y: 120
        width: 287
        height: 40
        font.pixelSize: 25
        maximumLength: 16
    }

    Text {
        id: element1
        x: 89
        y: 133
        width: 111
        height: 14
        text: qsTr("server name")
        font.pixelSize: 12
    }

    Text {
        id: element2
        x: 89
        y: 204
        width: 111
        height: 14
        text: qsTr("user name")
        font.pixelSize: 12
    }

    TextInput {
        id: identif1
        x: 164
        y: 191
        width: 287
        height: 40
        maximumLength: 16
        font.pixelSize: 25
    }

    Button {
        id: button1
        x: 258
        y: 276
        text: qsTr("login")
    }
}
