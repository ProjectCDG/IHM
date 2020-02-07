import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    id: page

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

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
