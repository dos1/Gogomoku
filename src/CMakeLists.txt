SET(gogomoku_SRCS
	main.cpp
	mainwindow.cpp
)

kde4_add_ui_files(gogomoku_SRCS mainwindow.ui)

kde4_add_executable(gogomoku ${gogomoku_SRCS})
target_link_libraries(gogomoku ${KDE4_KDEUI_LIBS})

install(TARGETS gogomoku DESTINATION ${BIN_INSTALL_DIR})
