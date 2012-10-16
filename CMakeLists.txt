PROJECT(gogomoku)
FIND_PACKAGE(Qt4 REQUIRED)

cmake_minimum_required(VERSION 2.8)

SET(gogomoku_SOURCES main.cpp mainwindow.cpp)
SET(gogomoku_HEADERS mainwindow.h)
SET(gogomoku_FORMS mainwindow.ui)

QT4_WRAP_CPP(gogomoku_HEADERS_MOC ${gogomoku_HEADERS})
QT4_WRAP_UI(gogomoku_FORMS_HEADERS ${gogomoku_FORMS})

QT4_AUTOMOC(${gogomoku_SRCS})

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

ADD_EXECUTABLE(gogomoku ${gogomoku_SOURCES} 
    ${gogomoku_HEADERS_MOC} ${gogomoku_FORMS_HEADERS} )
TARGET_LINK_LIBRARIES(gogomoku ${QT_LIBRARIES})
