---
title: Quickstart - CMake
nav_order: 5
---

# Quickstart Guide - CMake


## Dependencies

liburdf currently depends on the following libraries:

- [TinyXML2](https://github.com/leethomason/tinyxml2)
- [loguru](https://github.com/emilk/loguru)
- [Eigen3](https://eigen.tuxfamily.org)
- [cxxopts](https://github.com/jarro2783/cxxopts)
- [assimp](https://github.com/assimp/assimp)

These are mainly for developers or for building language interfaces:

- [pybind11](https://github.com/pybind/pybind11)
- [googletest](https://github.com/google/googletest)

These dependencies are automatically fetched and compiled during the build process no sperate installation is required.


##### 2.1.4.1 Prerequisites

1. C++17 compatible compiler (GCC 7.1+, Clang 5.0+, MSVC 2017+)
2. CMake (version 3.10+)
  
##### 2.1.4.2 Configuration Options

| Option                  | Description                          | Default |
|--------------------------|--------------------------------------|---------|
| LIBURDF_BUILD_SHARED     | Build shared library                 | OFF     |
| LIBURDF_BUILD_SCRIPTS    | Enable building C++ scripts          | ON      |
| LIBURDF_BUILD_TESTS      | Enable building C++ tests            | ON      |
| LIBURDF_BUILD_PYTHON3    | Enable building Python3 binaries     | ON      |
| LIBURDF_INSTALL          | Enable installation of liburdf       | ON      |


##### 2.1.4.3 Build 

We recommend using **Ninja** for faster builds. Run the following commands to build the project:

```bash
mkdir build && cd build
cmake -G Ninja  ..
ninja
ninja install 
```

By default, this will use the MSVC compiler on Windows and the default CMake options.
To use a different compiler with Ninja, run:

```bash
cmake -G Ninja -DCMAKE_CXX_COMPILER=g++ -DCMAKE_C_COMPILER=gcc ..
make 
make install 
```

for unix systems or MinGW on Windows, If you prefer not to use Ninja, you can build the project using Unix Makefiles:  

```bash
mkdir build && cd build
cmake -G "Unix Makefiles" ..
make
make install 
```

These commands will build and install the static/shared library under the `lib/` directory and the include files in the `include/` directory of the build folder.

For Python bindings build and installation, enable the `-DLIBURDF_BUILD_PYTHON3=ON` flag, and run the following command from the root of the project to install them locally.

> ```bash  
> pip install --user .  
> ```  
> Note that Python bindings are not currently tested, many bugs exist. Use them at your own risk, or feel free to contribute