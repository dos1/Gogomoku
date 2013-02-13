import Qt 4.7

Item {
    id: gameView
    anchors.fill: parent

    Flickable {
            id: boardFlickable
            anchors.fill: parent
            contentWidth: boardGrid.width/2
            contentHeight: boardGrid.height/2
            maximumFlickVelocity: 1000
            flickDeceleration: 2000

            // This implements "Fluid" 3D tilting
            /*transform: [
            Rotation {
                origin.x: gameView.width / 2
                origin.y: gameView.height / 2
                axis { x: 1; y: 0; z: 0 }
                angle: true ? Math.min(Math.max(-boardFlickable.verticalVelocity / 4, -75), 75) : 0
                Behavior on angle { SpringAnimation { spring: 1.5; damping: 0.75 } }
            },
            Rotation {
                origin.x: gameView.width / 2
                origin.y: gameView.height / 2
                axis { x: 0; y: 1; z: 0 }
                angle: true ? Math.min(Math.max(boardFlickable.horizontalVelocity / 4, -75), 75) : 0
                Behavior on angle { SpringAnimation { spring: 1.5; damping: 0.75 } }
            }
            ]*/

        Grid {
            //anchors.fill: parent
            // Board is 19x19 tiles
            id: boardGrid
            columns: 19
            spacing: 3
            transform: Scale { xScale: 0.5; yScale: 0.5}
            property int lol: 0

            Repeater {
                model: 19*19
                Tile {
                    state: 0
                    //width: modelData
                    width: (gameView.width*2-3*18)/19 < 64 ? 64 :(gameView.width*2-3*18)/19
                    height: width
                    number: modelData
                  //anchors.fill: parent
                }
            }
        }

}
    ScrollBar {
        flickable: boardFlickable
        vertical: true
    }

    ScrollBar {
        flickable: boardFlickable
        vertical: false
    }
}
