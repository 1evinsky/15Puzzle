import QtQuick 2.0

Rectangle {
    id: root

    property string displayText: ""

    color: "lightseagreen"

    radius: 20

    border{
        color: "black"
        width: 2
    }

    Text {
        id: _firstText
        anchors.centerIn: root
        text: root.displayText
        font{
            pointSize: Math.min(root.width, root.height) / 10
            bold: true
        }
    }
}
