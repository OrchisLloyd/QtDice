cmake_minimum_required(VERSION 3.0)
project(QtDice CXX)

message(STATUS "CMAKE_GENERATOR: ${CMAKE_GENERATOR}")
message(STATUS "CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Instruct CMake to create code from Qt designer ui files
set(CMAKE_AUTORCC ON)

set(QtDice_VERSION_MAJOR 0)
set(QtDice_VERSION_MINOR 1)
set(QtDice_VERSION ${QtDice_VERSION_MAJOR}.${QtDice_VERSION_MINOR})

set(Dice_VERSION_MAJOR 1)
set(Dice_VERSION_MINOR 0)
set(CMAKE_BUILD_TYPE "Release")
configure_file(${PROJECT_SOURCE_DIR}/src/version.h.in ${PROJECT_SOURCE_DIR}/src/headers/version.h @ONLY)

#file(GLOB TS_FILES "${PROJECT_SOURCE_DIR}/translations/*.ts")
#add_subdirectory(src/About)
add_subdirectory(src/Settings)
include_directories(src)

if(WIN32) # Check if we are on Windows
	set(PLATFORM_TARGET "WIN32")
	if(CMAKE_CXX_COMPILER_ID MATCHES MSVC) # Check if we are using the Visual Studio compiler.
		set(CMAKE_PREFIX_PATH "C:\\Qt\\5.12.0\\msvc2017_64\\")
	elseif(CMAKE_COMPILER_IS_GNUCXX)
		message(STATUS "Setting PATH...")
		set(CMAKE_PREFIX_PATH "C:\\Qt\\5.12.0\\mingw73_64\\;C:\\Qt\\5.12.0\\mingw73_64\\include\\")
	endif()
elseif(UNIX)
	#
elseif(APPLE)
	set(PLATFORM_TARGET "MACOSX_BUNDLE")
endif(WIN32)

option(ENABLE_SOUND "Enable rolling sound effect" OFF)
if(ENABLE_SOUND)
	message(STATUS "Enable rolling sound of the dice")
	add_definitions(-DENABLE_SOUND)
endif()
# Find the QtWidgets and Qt5Multimedia library
find_package(Qt5Widgets CONFIG REQUIRED)
qt5_add_resources(qtdice_RES src/dice.qrc)
if(ENABLE_SOUND)
	find_package(Qt5Multimedia CONFIG REQUIRED)
endif()

set(qtdice_SRC
	src/main.cpp
	src/qtdice.cpp
	src/Dice/dice.cpp
	#src/About/about.cpp
	src/Settings/configure.cpp
)

set(qtdice_H 
	src/headers/qtdice.h
	src/headers/configure.h
	src/headers/infotab.h
)

# Tell CMake to create the executable
add_executable(${CMAKE_PROJECT_NAME} ${PLATFORM_TARGET} ${qtdice_SRC} ${qtdice_RES})

if(WIN32) # Check if we are on Windows
	if(CMAKE_CXX_COMPILER_ID MATCHES MSVC) # Check if we are using the Visual Studio compiler.
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /std:c++latest ")
		set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
			WIN32_EXECUTABLE YES
			#COMPILE_OPTIONS 
			LINK_FLAGS "/ENTRY:mainCRTStartup /VERBOSE /MANIFEST:NO"
			LINK_LIBRARIES "kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib 
					ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib"
		)
	elseif(CMAKE_COMPILER_IS_GNUCXX)
		set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
<<<<<<< HEAD
			COMPILE_OPTIONS "-fuse-ld=gold"
			LINK_FLAGS "-Wl,--verbose -Wl,--trace"
=======
			COMPILE_OPTIONS "-mwindows;-fuse-ld=gold"
			#LINK_FLAGS "-Wl,--verbose -Wl,--trace"
>>>>>>> e41dfcdaaf016b941a30ef18f6b678029e96ba79
		)
	elseif(CMAKE_CXX_COMPILER_ID MATHES "Clang")
		message(STATUS "Compiler is: ${CMAKE_CXX_COMPILER_ID}")
	else()
		message(FATAL_ERROR "You are using an unsupported Windows compiler! (Not MSVC, Clang or GCC)")
	endif()
elseif(APPLE)
	set_target_properties(${PROJECT_NAME} PROPERTIES
			MACOSX_BUNDLE YES
	)
elseif(UNIX)
	find_package(ECM REQUIRED NO_MODULE)
	set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR})
	include(KDEInstallDirs)
	include(KDECMakeSettings)
	include(KDECompilerSettings)
	include(FeatureSummary)
else()
	message(SEND_ERROR "You are on an unsupported platform! (Not Win32, Mac OS X or Unix)")
endif(WIN32)

# Use the Widgets module from Qt 5.
target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Widgets)
if(ENABLE_SOUND)
	target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Multimedia)
endif()

# Install the executable
# install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION ${KDE_INSTALL_BINDIR})
# install(PROGRAMS QtDice.desktop DESTINATION ${KDE_INSTALL_APPDIR})
# install(PROGRAMS src/images/dice.png DESTINATION ${KDE_INSTALL_ICONDIR})
