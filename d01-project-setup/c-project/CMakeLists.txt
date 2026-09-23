# SECTION: Environment Variables

# The following environment variables are declared in the `mise.toml` file:
# PROJECT_NAME
# C_STANDARD
# BINARY_NAME

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

# Declares that a binary executable should be created from `src/main.cpp`
add_executable($ENV{BINARY_NAME} src/main.cpp)
#______________________________________________________________________________
