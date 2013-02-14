import Qt 4.7

Item {
    id: tile
    width: 80
    height: 80
    property int state: gameData.nextColor+1
    property int number: 0

    Component.onCompleted: updateTile()

    // Tile background rectangle
    Image {
        anchors.fill: parent
        smooth: true
        source: "images/tile_background.png"
        opacity: {
            if (!tile.parent) return 1.0;
            if (tile.number===tile.parent.highlighted) {
                explosion.on()
                return 1.0
            }
            else {
                explosion.off()
                return 0.75
            }
        }
        Behavior on opacity {
            //enabled: gameData.moves != 0
            NumberAnimation {
                properties:"opacity"
                duration: 500
            }
        }
    }

    function updateTile() {
        if (tile.state===1)
            image.source="images/tile_button2.png"
        else if (tile.state===2)
            image.source="images/tile_button1.png"
        else
            image.source=""
    }


    // Tile Button
    Image {
        id: image
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        smooth: true
        source: ""

        opacity: tile.state!==0
        Behavior on opacity {
            //enabled: gameData.moves != 0
            SequentialAnimation {
                NumberAnimation {
                    property: "opacity"
                    to: 0
                    duration: 100
                }
                ScriptAction {
                    script: updateTile()
                }

                NumberAnimation {
                    properties: "opacity"
                    duration: 250
                }

                ScriptAction {
                    script: updateTile()
                } // just in case
            }
        }
    }
    MouseArea {
        anchors.fill: parent
        enabled: tile.state===0
        onClicked: {
            parent.parent.highlighted=tile.number
            explosion.explode()
            tile.state=gameData.nextColor+1
            gameData.makeMove(tile.number/19,tile.number%19)
        }
    }
    Explosion {
        id: explosion
    }
}
