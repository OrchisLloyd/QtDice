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

option(ENABLE_SOUND "Enable rolling sound effect" OFF)
if(ENABLE_SOUND)
	message(STATUS "Enable rolling sound of the dice")
	add_definitions(-DENABLE_SOUND)
endif()
# Find the QtWidgets and Qt5Multimedia library
find_package(Qt5Widgets CONFIG REQUIRED)
if(ENABLE_SOUND)
	find_package(Qt5Multimedia CONFIG REQUIRED)
endif()

set(qtdice_SRC
  src/main.cpp
  src/qtdice.cpp
  src/Dice/dice.cpp
  src/About/about.cpp
  src/About/infotab.cpp
  src/Settings/configure.cpp
)

set(qtdice_RES
  share/dice.qrc)

# Tell CMake to create the executable
add_executable(${CMAKE_PROJECT_NAME} ${qtdice_SRC} 
        ${qtdice_RES} ${UI_H})

# Use the Widgets module from Qt 5.
target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Widgets Qt5::Multimedia)
#if(ENABLE_SOUND)
#	target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Multimedia)
#endif()

# Install the executable
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION ${KDE_INSTALL_BINDIR})
install(PROGRAMS QtDice.desktop DESTINATION ${KDE_INSTALL_APPDIR})
install(PROGRAMS share/images/dice.png DESTINATION ${KDE_INSTALL_ICONDIR})
