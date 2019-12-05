import QtQuick 2.0

Rectangle {
    id: _root
    color: "lightseagreen"

    radius: 20

    border{
        color: "black"
        width: 3
    }

    Text {
        id: _firstText
        anchors.centerIn: _root
        text: qsTr("1")
        font{
            pointSize: Math.min(_root.width, _root.height) / 10
            bold: true
        }
    }
}
