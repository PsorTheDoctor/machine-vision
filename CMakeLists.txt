cmake_minimum_required(VERSION 3.0.0)
project(machine-vision VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(machine-vision report_exercises/ex3_conv_filter.cpp)

target_link_libraries(machine-vision ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
