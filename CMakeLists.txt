cmake_minimum_required(VERSION 3.16)
project(trtle-qt VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
find_package(trtle REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(trtle-qt)
add_subdirectory(src)
target_include_directories(trtle-qt PRIVATE ${CMAKE_BINARY_DIR})
target_link_libraries(trtle-qt PRIVATE
    trtle::trtle
    Qt5::Widgets
)
