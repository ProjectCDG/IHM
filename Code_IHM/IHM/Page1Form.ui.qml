import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400


    Frame {
        id: frameidentif
        x: 157
        y: 128
        width: 287
        height: 40
    }

    TextInput {
        id: identif
        x: 157
        y: 128
        width: 287
        height: 40
        font.pixelSize: 25
        maximumLength: 16
    }

    Frame {
        id: framepassworrd
        x: 157
        y: 228
        width: 287
        height: 40
    }

    TextInput {
        id: password
        x: 157
        y: 228
        width: 287
        height: 40
        echoMode: TextInput.Password
        font.pixelSize: 25
        maximumLength: 16
    }

    Text {
        id: element
        x: 157
        y: 109
        width: 182
        height: 24
        text: qsTr("Identifiant :")
        font.pixelSize: 12
    }

    Text {
        id: element1
        x: 157
        y: 211
        width: 182
        height: 24
        text: qsTr("Mot de passe :")
        font.pixelSize: 12
    }

    Button {
        id: button
        x: 426
        y: 344
        text: qsTr("Se connecter")
    }

    Text {
        id: element2
        x: 120
        y: 17
        width: 362
        height: 49
        text: qsTr("Connexion")
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 43
    }
}
