import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    id: root
    property variant page2;
    visible: true
    width: 640
    height: 480
    title: qsTr("IHM Mesurer une piece")

/*

    Item {
        id : page2


        Page2Form {
        }
    }*/


    Item {
        id: page1

        Page1Form {
            connection.onClicked: {
                var component = Qt.createComponent("Page2Form.ui.qml");
                   page2 = component.createObject(root);
                   page2.show();
            }


        }
    }





    /*      Page2Form {

        }
        Page3Form {

        }
        Page4Form {

        }*/






    /* footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Page 1")
        }
        TabButton {
            text: qsTr("Page 2")
        }
        TabButton {
            text: qsTr("Page 3")
        }
        TabButton {
            text: qsTr("Page 4")
        }

    }*/
}
