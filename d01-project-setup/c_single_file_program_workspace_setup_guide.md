# C Single-File Program Workspace Setup Guide
_______________________________________________________________________________

Create the project directory and enter it
```bash
mkdir c-single-file-program-workspace && cd c-single-file-program-workspace
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

#______________________________________________________________________________

[shell_alias]
build = "mise buildfile"
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

mkdir programs

mkdir programs/d01-topic-one
touch programs/d01-topic-one/f01_alpha.c
touch programs/d01-topic-one/f02_bravo.c

mkdir programs/d02-topic-two
touch programs/d02-topic-two/f01_charlie.c
touch programs/d02-topic-two/f02_delta.c

mkdir .mise-tasks 
touch .mise-tasks/buildfile.bash 
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

# This line is used to create a list of all the `.cpp` files in the project
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
```
_______________________________________________________________________________

Add this to the `.mise-tasks/buildfile.bash` file
```bash
#!/usr/bin/env bash

#MISE description="👷 Build a specific .c file | alias = build"
#MISE quiet=true

#______________________________________________________________________________

# STEP: 1 => Create a name for the binary

if [ -z "$1" ]; then
    printf "\n%s\n" '❌ Error:'
    printf "%s\n\n" 'You did not specify which .c file to build'
    printf "%s\n" 'Usage:'
    printf "%s\n\n" 'mise build-file f01_alpha.c'
    exit 1
fi

BINARY_NAME=$(basename "$1" .c)
#______________________________________________________________________________

# STEP: 2 => Generate the build instructions if they have not been generated

if [ ! -d "build" ]; then
    if ! cmake -B build -G Ninja &> /dev/null; then
        printf "\n%s\n\n" '❌ Failed to generate build instructions'
        exit 1
    fi
fi
#______________________________________________________________________________

# STEP: 3 => Build the specific file

if ! cmake --build build --target "$BINARY_NAME" &> /dev/null; then
    printf "\n%s\n\n" "❌ Failed to build target: $BINARY_NAME"
    exit 1
fi
#______________________________________________________________________________

printf "\n%s\n\n" "✅ $BINARY_NAME has been built"
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

Add this to the `programs/d01-topic-one/f01_alpha.c` file
```c
#include <stdio.h>

int main(void) {
    printf("\nThis is f01_alpha\n\n");
    return 0;
}
```
_______________________________________________________________________________

Add this to the `programs/d01-topic-one/f02_bravo.c` file
```c
#include <stdio.h>

int main(void) {
    printf("\nThis is f02_bravo\n\n");
    return 0;
}
```
_______________________________________________________________________________

Add this to the `programs/d02-topic-two/f01_charlie.c` file
```c
#include <stdio.h>

int main(void) {
    printf("\nThis is f01_charlie\n\n");
    return 0;
}
```
_______________________________________________________________________________

Add this to the `programs/d02-topic-two/f02_delta.c` file
```c
#include <stdio.h>

int main(void) {
    printf("\nThis is f02_delta\n\n");
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

Add this to the `.mise-tasks/runbin.bash` file
```bash
#!/usr/bin/env bash

#MISE description="🤖 Run the binary of a .c file | alias = run"
#MISE quiet=true

#______________________________________________________________________________

# STEP: 1 => Create a name for the specific binary that should be built

if [ -z "$1" ]; then
    printf "\n%s\n" '❌ Error:'
    printf "%s\n\n" 'You did not specify which .c file to build'
    printf "%s\n" 'Usage:'
    printf "%s\n\n" 'mise run-bin f01_alpha.c'
    exit 1
fi

BINARY_NAME=$(basename "$1" .c)
#______________________________________________________________________________

# STEP: 2 => Generate the build instructions if they have not been generated

if [ ! -d "build" ]; then
    if ! cmake -B build -G Ninja &> /dev/null; then
        printf "\n%s\n\n" '❌ Failed to generate build instructions'
        exit 1
    fi
fi

#______________________________________________________________________________

# STEP: 3 => Build the specific file

if ! cmake --build build --target "$BINARY_NAME" &> /dev/null; then
    printf "\n%s\n\n" "❌ Failed to build target: $BINARY_NAME"
    exit 1
fi
#______________________________________________________________________________

# STEP: 4 => Run the binary

./build/"$BINARY_NAME"
```
_______________________________________________________________________________

To view a list of `mise tasks`, run this command
```bash
mise tasks
```

You should get an output like this
```
Name       Description
buildfile  👷 Build a specific .c file | alias = build
clean      🧼 Delete build and cache files | alias = clean
runbin     🤖 Run the binary of a .c file | alias = run
structure  🌲 View project structure as a tree diagram | alias = structure
```
_______________________________________________________________________________
