import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    Text {
        id: titre
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
        id: suivantP5
        x: 482
        y: 349
        text: qsTr("Suivant")
    }

    Frame {
        id: frameServer
        x: 164
        y: 120
        width: 287
        height: 40
    }

    TextInput {
        id: server
        x: 164
        y: 120
        width: 287
        height: 40
        font.pixelSize: 25
        maximumLength: 16
    }

    Text {
        id: textServer
        x: 89
        y: 133
        width: 111
        height: 14
        text: qsTr("server name")
        font.pixelSize: 12
    }

    Text {
        id: textUser
        x: 89
        y: 204
        width: 111
        height: 14
        text: qsTr("user name")
        font.pixelSize: 12
    }

    TextInput {
        id: userName
        x: 164
        y: 191
        width: 287
        height: 40
        maximumLength: 16
        font.pixelSize: 25
    }

    Button {
        id: logginPara
        x: 258
        y: 276
        text: qsTr("login")
    }

    Frame {
        id: frameUserName
        x: 164
        y: 191
        width: 287
        height: 40
    }
}
