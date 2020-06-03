# Macarons
Macarons is a tool that allows you to generate a header file with version data pulled from the Git repository located in the solution. This is particularly useful because you can have the version of your app automatically available inside of your code.

This tool is a portable executable that you can invoke in your post-build step to generate the header with version information.

## Example Usage

### Printing the version in a console app

```cpp
#include <iostream>
#include <Macarons.h>

int main(int argc, char** argv)
{
    if (argv[1] == "-v")
    {
        std::cout << "App version is " << MACARONS_VER_LONG << std::endl;
    }

    return 0;
}

```

### Showing a dialog box with the app version

```cpp
#include <Windows.h>
#include <Macarons.h>

MessageBox(
        NULL,
        L"The app version is " + MACARONS_VER_LONG,
        L"App Version",
        MB_ICONINFORMATION | MB_OK
    );
```

### Generated header

```cpp
    // Macarons.h
    #pragma once

    #define MACARONS_VER_LONG   "1.3.5 beta2"
    #define MACARONS_VER_SHORT  "1.3.5"

    #define MACARONS_VER_MAJOR  1
    #define MACARONS_VER_MINOR  3
    #define MACARONS_VER_PATCH  5
```

## Getting Started

Visual Studio 2019 is recommended for building the project from source.

You can clone the repository to your computer using Git:

```
git clone --recursive https://github.com/AlexandruIstrate/Macarons
```

Make sure to use the ```--recursive``` flag to fetch all of the submodules!