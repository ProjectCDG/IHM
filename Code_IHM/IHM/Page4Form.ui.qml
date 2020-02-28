import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400
    property alias textPas: textPas
    property alias pas: pas
    property alias tarVide: tarVide
    property alias tarConnue: tarConnue
    property alias axeZMoins: axeZMoins
    property alias axeZPlus: axeZPlus
    property alias axeXPlus: axeXPlus
    property alias axeYMoins: axeYMoins
    property alias axeXMoins: axeXMoins
    property alias axeYPlus: axeYPlus

    Text {
        id: titre
        x: 171
        y: 13
        width: 259
        height: 43
        text: qsTr("Calibrage et Tar")
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

    Button {
        id: axeYPlus
        x: 259
        y: 72
        width: 83
        height: 72
        text: qsTr("↑")
        font.pointSize: 30
        opacity:0
    }

    Button {
        id: axeXMoins
        x: 171
        y: 141
        width: 83
        height: 72
        text: qsTr("←")
        font.pointSize: 30
        opacity:0
    }

    Button {
        id: axeYMoins
        x: 259
        y: 214
        width: 83
        height: 72
        text: qsTr("↓")
        font.pointSize: 30
        opacity:0

    }

    Button {
        id: axeXPlus
        x: 347
        y: 141
        width: 83
        height: 72
        text: qsTr("→")
        font.pointSize: 30
        opacity:0
    }

    Button {
        id: axeZPlus
        x: 271
        y: 150
        width: 59
        height: 31
        text: qsTr("+")
        font.pointSize: 15
        opacity:0
    }

    Button {
        id: axeZMoins
        x: 271
        y: 182
        width: 59
        height: 31
        text: qsTr("-")
        font.pointSize: 15
        opacity:0
    }

    Button {
        id: tarConnue
        x: 30
        y: 266
        width: 106
        height: 48
        text: qsTr("Tar connue")

    }

    Button {
        id: tarVide
        x: 30
        y: 326
        width: 106
        height: 48
        text: qsTr("Tar à vide")
        opacity: 0;
    }

    SpinBox {
        id: pas
        x: 204
        y: 292
        stepSize: 50
        from: 1
        to: 1000
        editable: true
        opacity: 0



    }

    Text {
        id: textPas
        x: 204
        y: 346
        width: 192
        height: 23
        text: qsTr("Pas modifiable")
        font.bold: false
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 18
        opacity: 0
    }
}
