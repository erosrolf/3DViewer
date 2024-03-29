cmake_minimum_required(VERSION 3.5)

project(3DViewer VERSION 0.1 LANGUAGES CXX)

#set(CMAKE_PREFIX_PATH "/usr/local/Qt-6.6.2/lib/cmake")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets OpenGLWidgets)

link_libraries(${OPENGL_LIBRARIES})

set(PROJECT_SOURCES
    main.cc
    
    view/main_widget.cc
    view/main_widget.h
    view/main_widget.ui
    view/gl_view.cc
    view/gl_view.h
    view/icons/icons.qrc

    controller/controller.h

    core/obj_modifier_strategy/obj_modifier_strategy.h
    core/obj_modifier_strategy/translation_strategy.cc
    core/obj_modifier_strategy/rotate_strategy.cc
    core/obj_modifier_strategy/scale_strategy.cc
    core/obj_modifier_strategy/centring_strategy.cc
    core/model.h
    core/obj.h
    core/obj.cc
    core/model.h
    core/model.h
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::OpenGLWidgets)

set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()
