import QtQuick 1.1

Item {
    width: 640
    height: 640

    // *** Game View ***
    GameView {
        id: gameView
        enabled: true
    }

    // *** Game View Hider ***
    Rectangle {
        id: gameViewHider
        anchors.fill: parent
        color: "black"
        opacity: 0
        MouseArea {
            anchors.fill: parent
            enabled: gameData.state
        }
        states: [
            State {
                name: "show"
                when: gameData.state
                PropertyChanges {
                    target: gameViewHider
                    opacity: 0.75
                }
            }
        ]
        transitions: Transition {
            NumberAnimation {
                properties: "opacity"
                duration: 400
            }
        }

        Rectangle {
            id: newGame
            color: "black"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            width:280
            height:100
            radius:15

            states: [
                State {
                    name: "hover"
                    when: mycha.containsMouse
                    PropertyChanges {
                        target: newGame
                        opacity: 0.75
                    }
                }
            ]
            transitions: Transition {
                NumberAnimation {
                    properties: "opacity"
                    duration: 250
                }
            }

            Tile {
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.top: parent.top
                anchors.topMargin: 10
                state: gameData.state
                id: tile
            }

            Text {
                anchors.top: parent.top
                anchors.topMargin: 10
                anchors.left: tile.right
                anchors.leftMargin: 10
                font.pixelSize: 42
                color: "white"
                text: "Winner!"
            }

            Text {
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
                anchors.left: tile.right
                anchors.leftMargin: 10
                font.pixelSize: 14
                color: "white"
                text: "Click to start once again"
            }

            MouseArea {
                id: mycha
                anchors.fill: parent
                hoverEnabled: true
                onClicked: gameData.newGame()
            }
        }
    }
    // *** Main Menu panel ***
    /* MenuPanel {
            id: menuPanel
        } */
}

