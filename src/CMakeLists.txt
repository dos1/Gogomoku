SET(gogomoku_SRCS
	main.cpp
	mainwindow.cpp
	table.qml
	GameView.qml
	ScrollBar.qml
	Tile.qml
	Explosion.qml
)

qt4_add_resources(gogomoku_RCC_SRCS gogomoku.qrc)

kde4_add_ui_files(gogomoku_SRCS mainwindow.ui)

kde4_add_executable(gogomoku ${gogomoku_SRCS} ${gogomoku_RCC_SRCS})
target_link_libraries(gogomoku ${KDE4_KDEUI_LIBS} ${QT_QTDECLARATIVE_LIBRARY})

install(TARGETS gogomoku DESTINATION ${BIN_INSTALL_DIR})
