cmake_minimum_required(VERSION 2.8)
project(PP_Final C)

set(CMAKE_C_STANDARD 99)

# check for libpng
find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIRS})
message(${PNG_INCLUDE_DIRS})


add_executable(PP_Final_TestMain Tests/main.c matrix.h matrix.c image_processing.c image_processing.h)
add_executable(PP_Final_TestReadPNG Tests/read_png.c matrix.h matrix.c image_processing.c image_processing.h)
target_link_libraries(PP_Final_TestReadPNG ${PNG_LIBRARIES})