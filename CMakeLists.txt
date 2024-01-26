cmake_minimum_required(VERSION 3.5)

project(dbus-system-share)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)

# Add source files here
set(SOURCES
        DBusInterface.cpp
        DBusInterface.h
        FileFormatRegistry.cpp
        FileFormatRegistry.h
        FileOpenListener.cpp
        FileOpenListener.h
        MyFileOpenListener.h
        main.cpp
)

# Add any additional dependencies here
find_package(Qt5 REQUIRED COMPONENTS DBus Widgets Core)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link the necessary libraries
target_link_libraries(${PROJECT_NAME} Qt5::DBus Qt5::Widgets Qt5::Core)
