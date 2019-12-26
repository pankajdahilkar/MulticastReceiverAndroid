import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello Pankaj")

    function setTextField(text){
        console.log("setTextField: " + text)
        helloText.text = text
    }

    Rectangle {
        id: page
       anchors.fill: parent
        color: "lightgray"

        Text {
            id: helloText
            text: "Multicast Receiver"
            y: 30
            anchors.horizontalCenter: page.horizontalCenter
            width: parent.width
            minimumPixelSize: 1
            wrapMode: Text.WordWrap
            horizontalAlignment:Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 20; font.bold: true
        }


}
}
