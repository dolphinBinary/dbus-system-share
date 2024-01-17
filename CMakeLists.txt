cmake_minimum_required(VERSION 3.5)

project(YourProjectName)

set(CMAKE_CXX_STANDARD 17)

# Add your source files here
set(SOURCES
        DBusInterface.cpp
        DBusInterface.h
        FileFormatRegistry.cpp
        FileFormatRegistry.h
        FileOpenListener.cpp
        FileOpenListener.h
        main.cpp
)

# Add any additional dependencies here
find_package(Qt5 REQUIRED COMPONENTS Core)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link the necessary libraries
target_link_libraries(${PROJECT_NAME} Qt5::Core)
