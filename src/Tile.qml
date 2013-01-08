import Qt 4.7

Item {
    id: tile
    width: 80
    height: 80
    property int state: 1

    // Tile background rectangle
    Image {
        anchors.fill: parent
        smooth: true
        source: "images/tile_background.png"
        opacity: {
            //if (modelData.highlighted)
            //    return 1.0
            //else
                return 0.8
        }
        Behavior on opacity {
            //enabled: gameData.moves != 0
            NumberAnimation {
                properties:"opacity"
                duration: 500
            }
        }
    }
    // Tile Button
    Image {
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        smooth: true
        source: {
            if (tile.state===1)
                "images/tile_button1.png"
            else if (tile.state===2)
                "images/tile_button2.png"
            else
                ""
        }
        opacity: tile.state!==0
        Behavior on opacity {
            //enabled: gameData.moves != 0
            NumberAnimation {
                properties: "opacity"
                duration: 500
            }
        }
    }
    MouseArea {
        anchors.fill: parent
        enabled: tile.state===0
        onClicked: {
            parent.parent.lol=parent.parent.lol+1
            tile.state=(parent.parent.lol%2)+1; //Math.random()%2+1
            explosion.explode()
            //gameData.flip(index)
        }
    }
    Explosion {
        id: explosion
    }
}
