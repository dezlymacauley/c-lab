# C Project Setup Guide
_______________________________________________________________________________

Create the project directory and enter it
```bash
mkdir c-project && cd c-project
```
_______________________________________________________________________________

Create a `mise.toml` file and give mise permission to read it
```bash
touch mise.toml && mise trust
```
_______________________________________________________________________________

Add this to the `mise.toml` file
```bash
[tools]

# `cmake` is used to read `CMakeLists.txt` files,
# and generate build instructions for a specified build generator.
# The build generator used in this project is `ninja`.

# In addition to this, `cmake` is also responsible for creating 
# a `compile_commands.json` file. This file helps language servers 
# like `clangd` to understand the structure of your C project,
# and see which external dependencies you've added to the project,
# so that you get better language support and autocompletion.

# Once the build instructions have been generated,
# `cmake` can then trigger the build generator `ninja`.

# `ninja` will then use the C compiler specified to build the project and
# create a binary executable.
# The C compiler used in this project is `clang`
cmake = "latest"

# The build generator
ninja = "latest"

# The C compiler that will be used by build generator to build the project
# and create an executable binary.
clang = "latest"

# A Code formatter
clang-format = "latest"

# Language support for C files
# The `github:` prefix is used to download a pre-compiled binary from GitHub.
"github:clangd/clangd" = "latest"

# Language support for CMake files
# The `pipx:` prefix is used to download the Python package from PyPI.
# Despite the prefix `pipx`, it is actually using uv to download the tool.
"pipx:cmake-language-server" = { 
    version = "latest", 
    # cmake-language-server is not compatible with pygls version 2,
    # so this is required for it work.
    uvx_args = "--with pygls<2" 
}

# Displays the project structure as a tree diagram
eza = "latest"

#______________________________________________________________________________

[env]

PROJECT_NAME = "c-project"
BUILD_GENERATOR = "Ninja"
C_COMPILER = "clang"

# Use this site to see a list of valid C standards
# https://www.c-language.org/
C_STANDARD = "23"

BUILD_DIR = "build"
BINARY_NAME = "c-project"

# This is the command that will generate the build instructions
# To check if this works, run this:
# bash -c "$CMAKE_GBI_CMD"
CMAKE_GBI_CMD = """
cmake \
    -G {{env.BUILD_GENERATOR}} \
    -DCMAKE_C_COMPILER={{env.C_COMPILER}} \
    -B {{env.BUILD_DIR}}
"""

# This is the command that will build the project and create 
# a binary executable.
# To check if this works, run this:
# bash -c "$CMAKE_GBI_CMD" && bash -c "$CMAKE_BUILD_CMD"
CMAKE_BUILD_CMD = """
cmake --build {{env.BUILD_DIR}}
"""

# This is the command that will run the binary
# To check if this work, run this:
# bash -c "$RUN_BINARY_CMD"
RUN_BINARY_CMD = "./{{env.BUILD_DIR}}/{{env.BINARY_NAME}}"
#______________________________________________________________________________

[shell_alias]
build = "mise build"
clean = "mise clean"
run = "mise runbin"
structure = "mise structure"
#______________________________________________________________________________
```
_______________________________________________________________________________

Install the tools with mise
```bash
mise install
```
_______________________________________________________________________________

Create the project structure
```bash
touch .clang-format
touch .gitignore
touch CMakeLists.txt

mkdir src
touch src/main.c

mkdir .mise-tasks 
touch .mise-tasks/build.bash 
touch .mise-tasks/clean.bash 
touch .mise-tasks/runbin.bash 
touch .mise-tasks/structure.bash 
chmod u+x .mise-tasks/*.bash
```
_______________________________________________________________________________

Add this to the `.clang-format` file
```yaml
# ABOUT: .clang-format

# This file is used to configure the settings 
# for the code formatter `clang-format`.

# Use the link below to search for additional configuration options:

# https://clang.llvm.org/docs/ClangFormatStyleOptions.html
#______________________________________________________________________________

# This tells clang-format that the file contains C code.
Language: C

# Ensure that tab characters are never used.
# Any tab characters in the existing file will be replaced with spaces.
UseTab: Never

# Number of spaces for indentation
IndentWidth: 4

# Number of characters per line
ColumnLimit: 80
```
_______________________________________________________________________________

Add this to the `.gitignore` file
```bash
# Language Server Cache
/.cache/

# Build Output
/build/
```
_______________________________________________________________________________

Add this to the `CMakeLists.txt` file
```cmake
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

# Declares that a binary executable should be created from `src/main.c`
add_executable($ENV{BINARY_NAME} src/main.c)
#______________________________________________________________________________
```
_______________________________________________________________________________

Add this to the `.mise-tasks/build.bash` file
```bash
#!/usr/bin/env bash

#MISE description="👷 Build the project | alias = build"
#MISE quiet=true

#______________________________________________________________________________

# STEP: 1 => Generate the build instructions 

# The first `if` block ensures that CMake will only generate 
# build instructions if the `build` directory does not exist.

if [ ! -d "build" ]; then

    # This creates a clean cli output because the output messages from
    # the `CMAKE_GBI_CMD` command will only be shown if an error occured
    # when generating the the build instructions.
    if ! build_instruction_error_messages=$($CMAKE_GBI_CMD 2>&1); then
        printf "\n%s\n\n" '❌ Failed to generate build instructions:'
        printf "%s\n" "$build_instruction_error_messages"
        exit 1
    fi

fi

#______________________________________________________________________________

# STEP: 2 => Build the project

# This creates a clean cli output because the output messages from
# the `CMAKE_BUILD_CMD` command will only be shown if an error occured
# when building the project.
if ! build_output_error_messages=$($CMAKE_BUILD_CMD 2>&1); then
    printf "\n%s\n\n" '❌ Failed to build project'
    printf "%s\n" "$build_output_error_messages"
    exit 1
fi

#______________________________________________________________________________

printf "\n%s\n\n" '✅ All programs in the workspace have been built'
#______________________________________________________________________________
```
_______________________________________________________________________________

Add this to the `.mise-tasks/clean.bash` file
```bash
#!/usr/bin/env bash

#MISE description="🧼 Delete build and cache files | alias = clean"
#MISE quiet=true

rm -rf build
rm -rf .cache

printf "\n%s\n\n" '✅ build and cache files have been deleted'
```
_______________________________________________________________________________

Add this to the `.mise-tasks/runbin.bash` file
```bash
#!/usr/bin/env bash

#MISE description="🤖 Run the binary of the project | alias = run"
#MISE quiet=true

#______________________________________________________________________________

# STEP: 1 => Generate the build instructions 

# The first `if` block ensures that CMake will only generate 
# build instructions if the `build` directory does not exist.

if [ ! -d "build" ]; then

    # This creates a clean cli output because the output messages from
    # the `CMAKE_GBI_CMD` command will only be shown if an error occured
    # when generating the the build instructions.
    if ! build_instruction_error_messages=$($CMAKE_GBI_CMD 2>&1); then
        printf "\n%s\n\n" '❌ Failed to generate build instructions:'
        printf "%s\n" "$build_instruction_error_messages"
        exit 1
    fi

fi

#______________________________________________________________________________

# STEP: 2 => Build the project

# This creates a clean cli output because the output messages from
# the `CMAKE_BUILD_CMD` command will only be shown if an error occured
# when building the project.
if ! build_output_error_messages=$($CMAKE_BUILD_CMD 2>&1); then
    printf "\n%s\n\n" '❌ Failed to build project'
    printf "%s\n" "$build_output_error_messages"
    exit 1
fi

#______________________________________________________________________________

# STEP: 3 => Run the binary executable 

bash -c "$RUN_BINARY_CMD"

#______________________________________________________________________________
```
_______________________________________________________________________________

Add this to the `.mise-tasks/structure.bash` file
```bash
#!/usr/bin/env bash

#MISE description="🌲 View project structure as a tree diagram | alias = structure"
#MISE quiet=true

eza --tree --all --git-ignore
#______________________________________________________________________________
```
_______________________________________________________________________________

Add this to the `src/main.c` file
```c
#include <stdio.h>

int main(void) {
    printf("\nC Project\n\n");
    return 0;
}
```
_______________________________________________________________________________

To view a list of `mise tasks`, 
run this command:
```bash
mise tasks
```

You should see this
```bash
Name       Description
build      👷 Build the project | alias = build
clean      🧼 Delete build and cache files | alias = clean
runbin     🤖 Run the binary of the project | alias = run
structure  🌲 View project structure as a tree diagram | alias = structure
```
_______________________________________________________________________________
