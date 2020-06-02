# Macarons
Macarons is a tool that allows you to generate a header file with version data pulled from the Git repository located in the solution. This is particularly useful because you can have the version of your app automatically available inside of your code.

## Example Usage
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

<details>
    <summary>Generated header</summary>
  
    ```cpp
    // Macarons.h
    #pragma once

    #define MACARONS_VER_LONG   "1.3.5 beta2"
    #define MACARONS_VER_SHORT  "1.3.5"

    #define MACARONS_VER_MAJOR  1
    #define MACARONS_VER_MINOR  3
    #define MACARONS_VER_PATCH  5
    ```
  
</details>