# The minimum version of `cmake` needed to run this file
cmake_minimum_required(VERSION 4.4.3)

# The first argument is the project name
# The second argument `LANGUAGES C`, 
# is used to specify that this project only uses C
project(c-project LANGUAGES C)

# Sets the C standard that should be used to compile the project
# You can check what is the latest standard from this website. 
# https://www.c-language.org/
# For maximum compatibility, use the second latest standard
set(CMAKE_C_STANDARD 17)

# Ensures that build fails if the compiler version does not support 
# the C standard that is set in this file
set(CMAKE_C_STANDARD_REQUIRED ON)

# This will create a binary executable called `c-project`,
# using the source file `src/main.c`
add_executable(c-project src/main.c)
