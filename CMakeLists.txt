cmake_minimum_required(VERSION 3.10)
project(qt)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(qt src/QtDecomp.cc)
target_include_directories(qt PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(qt ${OpenCV_LIBS})
