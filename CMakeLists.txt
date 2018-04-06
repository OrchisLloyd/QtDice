cmake_minimum_required(VERSION 3.0)
project(QtDice)
include(GNUInstallDirs)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Instruct CMake to create code from Qt designer ui files
set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTORCC ON)

set(QtDice_VERSION_MAJOR 0)
set(QtDice_VERSION_MINOR 2)
set(QtDice_VERSION ${QtDice_VERSION_MAJOR}.${QtDice_VERSION_MINOR})

set(Dice_VERSION_MAJOR 1)
set(Dice_VERSION_MAJOR 0)

configure_file(${PROJECT_SOURCE_DIR}/src/version.h.in ${PROJECT_SOURCE_DIR}/src/version.h @ONLY)

#file(GLOB TS_FILES "${PROJECT_SOURCE_DIR}/translations/*.ts")
add_subdirectory(src/About)
include_directories(src/)
# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Multimedia CONFIG REQUIRED)
set(UI_SOURCES
    src/qtdice.ui
    src/userwidget.ui
    src/usermenu.ui
    src/challengr.ui)
qt5_wrap_ui(UI_H ${UI_SOURCES})

set(qtdice_SRC
  src/main.cpp
  src/qtdice.cpp
  src/userwidget.cpp
  src/usermenu.cpp
  src/challenge.cpp
  src/Dice/dice.cpp
  src/About/about.cpp
)

set(qtdice_RES
  src/dice.qrc)

option(USER_MODE "Enable the user mode to save user's score etc" OFF)
if(USER_MODE)
	message(STATUS "Enabled user mode")
	add_definitions(-DUSER_MODE)
endif()

# Tell CMake to create the executable
add_executable(${CMAKE_PROJECT_NAME} ${qtdice_SRC} 
        ${qtdice_RES} ${UI_H})

# Use the Widgets module from Qt 5.
target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Widgets Qt5::Multimedia)

# Install the executable
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION CMAKE_INSTALL_BINDIR)
