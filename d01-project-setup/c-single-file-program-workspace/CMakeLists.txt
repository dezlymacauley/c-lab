cmake_minimum_required(VERSION 3.20)

project(c-single-file-workspace LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Find all .c files recursively inside the programs directory
file(GLOB_RECURSE PROGRAM_SOURCES CONFIGURE_DEPENDS "programs/*.c")

foreach(SOURCE_FILE ${PROGRAM_SOURCES})
    # Extract filename without extension (e.g., f01_alpha)
    get_filename_component(TARGET_NAME ${SOURCE_FILE} NAME_WE)
    
    # Register each source file as its own standalone executable target
    add_executable(\({TARGET_NAME}\){SOURCE_FILE})
endforeach()
