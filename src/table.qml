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
        opacity: 0.7
        MouseArea {
            anchors.fill: parent
            enabled: gameData.state
        }
        states: [
            State {
                name: "hide"
                when: gameData.state===0
                PropertyChanges {
                    target: gameViewHider
                    opacity: 0
                }
            }
        ]
        transitions: Transition {
            NumberAnimation {
                properties: "opacity"
                duration: 400
            }
        }
    }
    // *** Main Menu panel ***
    /* MenuPanel {
            id: menuPanel
        } */
}

