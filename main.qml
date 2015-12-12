import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    x: 0
    y: 0
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Column{
        anchors.fill: parent

        Row{

            ListView{
                id: list
                model: myModel
                highlightFollowsCurrentItem: true
                width: 200
                height: 200
                delegate: Label{
                    property var myData: model
                    text: aName
                    MouseArea{
                        anchors.fill: parent
                        onClicked: list.currentIndex = index
                    }
                }
            }

            Grid{
                columns: 2
                Label{text: list.currentItem.myData.aName}
                Button{text: "Change name"; onClicked: list.currentItem.myData.aName = "new Name"}

                Label{text: list.currentItem.myData.aId}
                Button{text: "+1"; onClicked: list.currentItem.myData.aId += 1}

                Label{text: list.currentItem.myData.aX}
                Button{text: "+10"; onClicked: list.currentItem.myData.aX += 10}

                Label{text: list.currentItem.myData.aY}
                Button{text: "+5"; onClicked: list.currentItem.myData.aY += 5}
            }
        }
    }
}

