import QtQuick 2.12
import QtQuick.Controls 2.5


ApplicationWindow {
    id: root
    visible: true
    width: 640
    height: 480

    title: qsTr("IHM Mesurer une piece")
    property var page2
    property var page3
    property var page4
    property var xtemp: 0
    property var ytemp: 0
    property var ztemp: 0


    Page4Form {


        axeYPlus.onClicked: {
            yposition.text = ytemp+1;
            ytemp= ytemp+1;
        }
        axeYMoins.onClicked: {
            yposition.text = ytemp-1;
            ytemp= ytemp-1;
        }
        axeXPlus.onClicked: {
            xposition.text = xtemp+1;
            xtemp= xtemp+1;
        }
        axeXMoins.onClicked: {
            xposition.text = xtemp-1;
            xtemp= xtemp-1;
        }
        axeZPlus.onClicked: {
            zposition.text = ztemp+1;
            ztemp= ztemp+1;
        }
        axeZMoins.onClicked: {
            zposition.text = ztemp-1;
            ztemp= ztemp-1;
        }
        tarVide.onClicked: {
            console.log("Affichage panneau de deplacement plateau");
            axeYPlus.opacity = 1;
            axeYMoins.opacity = 1;
            axeXPlus.opacity = 1;
            axeXMoins.opacity = 1;
            axeZPlus.opacity = 1;
            axeZMoins.opacity = 1;
            pas.opacity = 1;
            textPas.opacity = 1;
        }
        tarConnue.onClicked: {
            console.log("Affichage Tar à vide");
            tarVide.opacity = 1;


        }

    }


    /*
    Page3Form {
        suivantP4.onClicked: {
            console.log("test");
            var component = Qt.createComponent("Page4Form.ui.qml");
            page4 = component.createObject(root);
            page4.load();
        }
    }

    Page2Form {
        suivantP3.onClicked: {
            console.log("test");
            var component = Qt.createComponent("Page3Form.ui.qml");
            page3 = component.createObject(root);
            page3.show();
        }
    }

    Page1Form {
        focus: true
        id: page1
        connection.onClicked: {
            var component = Qt.createComponent("Page2Form.ui.qml");
            page2 = component.createObject(root);
            page2.exec();
        }
    }


*/


    /*StackView {
        id: stackView
        initialItem: "Page1Form.ui.qml"
        anchors.fill: parent
    }*/




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


