import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400
    property alias suivantP4: suivantP4

    Text {
        id: element
        x: 171
        y: 80
        width: 259
        height: 43
        text: qsTr("Choisir une pièce à mesurer")
        font.pixelSize: 20
    }

    Button {
        id: suivantP4
        x: 482
        y: 349
        text: qsTr("Suivant")
    }

}
