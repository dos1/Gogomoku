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

        Grid {
            //anchors.fill: parent
            // Board is 19x19 tiles
            id: boardGrid
            columns: 19
            spacing: 2
            transform: Scale { xScale: 0.5; yScale: 0.5}

            Repeater {
                model: 19*19
                Tile {
                    state: 0
                    //width: modelData
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
