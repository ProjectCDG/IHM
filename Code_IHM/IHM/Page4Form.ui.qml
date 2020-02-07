import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    Text {
        id: element
        x: 171
        y: 80
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

    Dial {
        id: dial
        x: 229
        y: 117
    }

}
