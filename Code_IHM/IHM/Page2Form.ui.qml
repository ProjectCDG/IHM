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
        text: qsTr("Choisir une pièce à mesurer")
        font.pixelSize: 20
    }

    Button {
        id: button
        x: 482
        y: 349
        text: qsTr("Suivant")
    }

    ComboBox {
        id: deroulpiece
        x: 230
        y: 153
    }

}
