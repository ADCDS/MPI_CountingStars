cmake_minimum_required(VERSION 2.8)
project(PP_Final C)

set(CMAKE_C_STANDARD 99)

# check for libpng
find_package(PNG REQUIRED)

# check for mpi
find_package(MPI REQUIRED)
include_directories(${PNG_INCLUDE_DIRS})
include_directories(${MPI_INCLUDE_PATH})


add_executable(PP_Final_TestImageProcessing Tests/image_processing_test.c src/matrix.h src/matrix.c src/image_processing.c src/image_processing.h src/png_manager.c src/png_manager.h)
add_executable(PP_Final_TestReadPNG Tests/read_png.c src/matrix.h src/matrix.c src/image_processing.c src/image_processing.h)
add_executable(PP_Final_TestPNGManager Tests/png_manager_test.c src/matrix.h src/matrix.c src/image_processing.c src/image_processing.h src/png_manager.c src/png_manager.h)
add_executable(PP_Final_TestReadPNGAndCountObjects Tests/read_png_count_objects_test.c src/matrix.h src/matrix.c src/image_processing.c src/image_processing.h src/png_manager.c src/png_manager.h)
add_executable(PP_Final_TestMain Tests/main.c src/matrix.h src/matrix.c src/image_processing.c src/image_processing.h src/png_manager.c src/png_manager.h)
add_executable(PP_Final_TestMPI Tests/mpi_test.c)

target_link_libraries(PP_Final_TestImageProcessing ${PNG_LIBRARIES})
target_link_libraries(PP_Final_TestReadPNG ${PNG_LIBRARIES})
target_link_libraries(PP_Final_TestPNGManager ${PNG_LIBRARIES})
target_link_libraries(PP_Final_TestReadPNGAndCountObjects ${PNG_LIBRARIES})
target_link_libraries(PP_Final_TestMain ${PNG_LIBRARIES} ${MPI_C_LIBRARIES})
target_link_libraries(PP_Final_TestMPI ${MPI_C_LIBRARIES})

if(MPI_COMPILE_FLAGS)
    set_target_properties(PP_Final_TestMPI PROPERTIES
            COMPILE_FLAGS "${MPI_C_COMPILE_OPTIONS}")
endif()

if(MPI_LINK_FLAGS)
    set_target_properties(PP_Final_TestMPI PROPERTIES
            LINK_FLAGS "${MPI_C_LINK_FLAGS}")
endif()