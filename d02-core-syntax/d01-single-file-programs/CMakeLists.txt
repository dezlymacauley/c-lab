# SECTION: Environment Variables

# The following environment variables are declared in the `mise.toml` file:
# PROJECT_NAME
# C_STANDARD

#______________________________________________________________________________

# SECTION: Basic Settings

# The minimum version of CMake required to create build instructions
# in this project
cmake_minimum_required(VERSION 4.4.3)

# This sets the project name and `LANGUAGES C` is the convention to tell
# CMake that this project uses C code.
project($ENV{PROJECT_NAME} LANGUAGES C)

# This set the C standard that should be used and ensures that the build 
# does not fallback to any other standards
set(CMAKE_C_STANDARD $ENV{C_STANDARD})
set(CMAKE_C_STANDARD_REQUIRED ON)

# This tells CMake to generate a `compile_commands.json` file 
# when generating build instructions for your project.
# This `compile_commands.json` is used by `clangd`,
# the language server for C projects.

# The `compile_commands.json` file helps clangd know about the structure 
# of your project and any external packages you have linked to the project 
# so that it can provide you with better language support and completion.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#______________________________________________________________________________

# SECTION: Declaring what internal files should be compiled

# This line is used to create a list of all the `.c` files in the project
# that should be built, and then store 
# that list as a variable that I have chosen to call `PROGRAMS_DIRECTORY`.

# `GLOB_RECURSE` and `"programs/*.c"` tell CMake 
# to search for all `.c` files inside the "programs" directory,
# including any sub-directories that contain `.c` files.

# `CONFIGURE_DEPENDS` tells CMake to check the file system of the project 
# for changes before building the project. So if you add, delete, or rename,
# things inside the `programs` directory,
# CMake will ensure that the variable `PROGRAMS_DIRECTORY` is updated.
file(GLOB_RECURSE PROGRAMS_DIRECTORY CONFIGURE_DEPENDS "programs/*.c")

# This is a `foreach` loop in CMake.
# It allows CMAKE to to perform a set of actions for each `.c` file in the
# the `programs` directory.
foreach(C_FILE ${PROGRAMS_DIRECTORY})

    # A `.c` file is built, a binary executable is created.
    # The line below allows you to set the name of the binary executable
    # in advance, and store it in a variable called `BINARY_NAME`.
    # `${C_FILE} NAME_WE` means that the `BINARY_NAME` is equal to the C file
    # without its file extension.
    # So if C_FILE = f01_alpha.c, and BINARY_NAME = f01_alpha
    get_filename_component(BINARY_NAME ${C_FILE} NAME_WE)

    # This is where you list what should be built and from which `.c` file
    # E.g. Build `f01_alpha` from `f01_alpha.c`
    add_executable(${BINARY_NAME} ${C_FILE})

endforeach()

#______________________________________________________________________________
