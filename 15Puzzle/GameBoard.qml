import QtQuick 2.0
import Game 1.0;

GridView {
    id: root
    model: GameBoardModel{

    }

    cellHeight: height / root.model.dimension
    cellWidth: width / root.model.dimension

    delegate: Item{
        id: _backGroundDelegate
        width: root.cellWidth
        height: root.cellHeight

        visible: display !== root.model.hiddenElementValue

        Tile{
            anchors.fill: _backGroundDelegate
            anchors.margins: 3

            displayText: display

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    root.model.move(index);
                }
            }
        }
    }
}
