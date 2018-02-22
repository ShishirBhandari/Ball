cmake_minimum_required(VERSION 3.9)
project(Ball)

set(CMAKE_CXX_STANDARD 11)

link_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib"
        "${CMAKE_CURRENT_SOURCE_DIR}/lib/GL" )
link_libraries(mingw32 SDL2main SDL2)

find_package(GLEW REQUIRED)
if(GLEW_FOUND)
    link_libraries(glew32s OpenGL32)
endif(GLEW_FOUND)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
        "${CMAKE_CURRENT_SOURCE_DIR}/bin")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

set(SOURCE_FILES main.cpp MainGame.cpp MainGame.h)

add_executable(Ball ${SOURCE_FILES})