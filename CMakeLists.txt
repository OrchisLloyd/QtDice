cmake_minimum_required(VERSION 3.0)
project(QtDice)

find_package(ECM REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR})
include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)
include(FeatureSummary)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Instruct CMake to create code from Qt designer ui files
set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTORCC ON)

set(QtDice_VERSION_MAJOR 0)
set(QtDice_VERSION_MINOR 1)
set(QtDice_VERSION ${QtDice_VERSION_MAJOR}.${QtDice_VERSION_MINOR})

set(Dice_VERSION_MAJOR 1)
set(Dice_VERSION_MINOR 0)

configure_file(${PROJECT_SOURCE_DIR}/src/version.h.in ${PROJECT_SOURCE_DIR}/src/version.h @ONLY)

#file(GLOB TS_FILES "${PROJECT_SOURCE_DIR}/translations/*.ts")
add_subdirectory(src/About)
add_subdirectory(src/Settings)
include_directories(src/)
# Find the QtWidgets and Qt5Multimedia library
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Multimedia CONFIG REQUIRED)
#set(UI_SOURCES
#    src/qtdice.ui
#    src/userwidget.ui
#    src/usermenu.ui
#    src/challenge.ui
#    src/About/about.ui
#    src/Settings/configure.ui)
#qt5_wrap_ui(UI_H ${UI_SOURCES})

set(qtdice_SRC
  src/main.cpp
  src/qtdice.cpp
  src/Dice/dice.cpp
  src/About/about.cpp
  src/Settings/configure.cpp
)

set(qtdice_RES
  src/dice.qrc)

option(ENABLE_SOUND "Enable rolling sound effect" OFF)
if(ENABLE_SOUND)
	message(STATUS "Enable rolling sound of the dice")
	add_definitions(-DENABLE_SOUND)
endif()

option(ENABLE_POPUP "Enable popup menu on QPushButton" OFF)
if(ENABLE_POPUP)
	message(STATUS "Enable popup menu on QPushButton")
	add_definitions(-DENABLE_POPUP)
endif()

# Tell CMake to create the executable
add_executable(${CMAKE_PROJECT_NAME} ${qtdice_SRC} 
        ${qtdice_RES} ${UI_H})

# Use the Widgets module from Qt 5.
target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Widgets Qt5::Multimedia)

# Install the executable
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION ${KDE_INSTALL_BINDIR})
install(PROGRAMS QtDice.desktop DESTINATION ${KDE_INSTALL_APPDIR})
install(PROGRAMS src/images/dice.png DESTINATION ${KDE_INSTALL_ICONDIR})
