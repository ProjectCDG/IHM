import QtQuick 2.12
import QtQuick.Controls 2.5


ApplicationWindow {
    id: root
    property variant page2;
    property variant page3;
    property variant page4;
    property variant identifGlobal;
    visible: true
    width: 640
    height: 480
    title: qsTr("IHM Mesurer une piece")
    
    

    
    Item {
        id: pages

        Page1Form {
            focus: true
            id: page1

            connection.onClicked: {
                var component = Qt.createComponent("Page2Form.ui.qml");
                page2 = component.createObject(root);
                page2.exec();

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

        Page3Form {
            suivantP4.onClicked: {
                console.log("test");
                var component = Qt.createComponent("Page4Form.ui.qml");
                page4 = component.createObject(root);
                page4.show();

            }
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


