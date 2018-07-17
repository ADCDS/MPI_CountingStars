cmake_minimum_required(VERSION 2.8)
project(PP_Final C)

set(CMAKE_C_STANDARD 99)

# check for libpng
find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIRS})


add_executable(PP_Final_TestMain Tests/main.c src/matrix.h src/matrix.c src/image_processing.c src/image_processing.h src/png_manager.c src/png_manager.h)
add_executable(PP_Final_TestReadPNG Tests/read_png.c src/matrix.h src/matrix.c src/image_processing.c src/image_processing.h)
add_executable(PP_Final_TestPNGManager Tests/png_manager_test.c src/matrix.h src/matrix.c src/image_processing.c src/image_processing.h src/png_manager.c src/png_manager.h)
add_executable(PP_Final_TestReadPNGAndCountObjects Tests/read_png_count_objects_test.c src/matrix.h src/matrix.c src/image_processing.c src/image_processing.h src/png_manager.c src/png_manager.h)
target_link_libraries(PP_Final_TestMain ${PNG_LIBRARIES})
target_link_libraries(PP_Final_TestReadPNG ${PNG_LIBRARIES})
target_link_libraries(PP_Final_TestPNGManager ${PNG_LIBRARIES})
target_link_libraries(PP_Final_TestReadPNGAndCountObjects ${PNG_LIBRARIES})