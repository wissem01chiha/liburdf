<!-- omit in toc -->
liburdf
========

[![CMake](https://github.com/wissem01chiha/liburdf/actions/workflows/cmake.yml/badge.svg)](https://github.com/wissem01chiha/liburdf/actions/workflows/cmake.yml)
[![Bazel](https://github.com/wissem01chiha/liburdf/actions/workflows/bazel.yml/badge.svg)](https://github.com/wissem01chiha/liburdf/actions/workflows/bazel.yml)
![GitHub License](https://img.shields.io/github/license/wissem01chiha/liburdf)

- [1.0 Why?](#10-why)
  - [1.3 Contact](#13-contact)
  - [1.4 Contributing](#14-contributing)
- [2.0 Quick Start Guide](#20-quick-start-guide)
  - [2.1 Build](#21-build)
    - [2.1.2 Dependencies](#212-dependencies)
    - [2.1.3 Platform/Compiler Support](#213-platformcompiler-support)
    - [2.1.4 CMake](#214-cmake)
      - [2.1.4.1 Prerequisites](#2141-prerequisites)
      - [2.1.4.2 Configuration Options](#2142-configuration-options)
      - [2.1.4.3 Build](#2143-build)
    - [2.1.5 Bazel](#215-bazel)
      - [2.1.5.1 Prerequisites](#2151-prerequisites)
      - [2.1.5.2 Configuration Options](#2152-configuration-options)
      - [2.1.5.4 Test](#2154-test)
- [3.0 Documentation](#30-documentation)
- [4.0 License](#40-license)

## 1.0 Why?

**liburdf** is the successor of the **tinyurdf** project, a lightweight C++17 library for reading and processing urdf model files. I started working on  tinyurdf back in 2024 with the goal of providing a replacement for traditional urdf manipulation tools, which rely heavily on the ros runtime, unix dependencies, or small python libraries.  

during that time, I faced many issues with closed kinematics tree structures, which existing tools were not friendly with. Visualization and graphical debugging of such models was very painful, not to mention that generating them from mesh or [CAD](https://fileinfo.com/filetypes/cad) files required licensed software with many limitations.  

the main goal of **liburdf** was to provide a free, cross‑platform, lightweight library with multiple language bindings to read, write, generate, and visualize kinematics trees, in a hierarchical xml based representation and convert them back to mesh files

however, this required a huge amount of work. I re‑uploaded the **tinyurdf** code under the same license terms with a few enhancements and fixes (hoping it will be useful for some people). The 3D visualization features, which relied heavily on [VTK](https://github.com/Kitware/VTK), has been removed. The focus shifted toward parsing and generation features.

The project was originally derived from [urdf-api](https://docs.ros.org/en/diamondback/api/urdf/html/) and still follows the listed specifications of the urdf file format.

Please feel free to open an [issue](https://github.com/wissem01chiha/liburdf/issues). I will try to address any concerns as best I can.

### 1.3 Contact

Feel free to  contact the maintainer through email at [mail](mailto:chihawissem08@gmail.com)

### 1.4 Contributing

liburdf is still under development, and we welcome contributions from newcomers and experienced open‑source enthusiasts.
If you are interested in collaborating, please see the [contributing](.github/CONTRIBUTING.md) guide or contact the maintainer via email (see section [1.2](#12-contact)).  

Due to time constraints, responses and pull‑request reviews may occasionally be delayed.Thank you for your understanding and support.

## 2.0 Quick Start Guide

### 2.1 Build

This section describes how to build liburdf from source using [cmake](https://cmake.org/) or [bazel](https://bazel.build/),

> [!NOTE]  
> The official build system for **liburdf** is **CMake**.  
> however, bazel will continue to be maintained for bazel‑based projects, primarily for integration purposes.  
> Issues may still arise; please report them in the [issue tracker](https://github.com/wissem01chiha/liburdf/issues).

#### 2.1.2 Dependencies

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

#### 2.1.3 Platform/Compiler Support

| Platform | Compiler            | CMake Version |
|----------|---------------------|---------------|
| Windows  | MSVC 2017           | 3.22.1        |
| Linux    | GCC 8               | Latest        |

Other platforms or compilers have not yet been tested. Please open an issue on [GitHub Issues](https://github.com/wissem01chiha/liburdf/issues) for any suspected bugs.

#### 2.1.4 CMake

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

#### 2.1.5 Bazel 

##### 2.1.5.1 Prerequisites

1. C++17 compatible compiler (GCC 7.1+, Clang 5.0+, MSVC 2017+)
2. Bazel (version >=9.0.1)
  
##### 2.1.5.2 Configuration Options

From the top level of the project folder run 

```bash
bazel build //...
```

##### 2.1.5.4 Test 

Project tests are build by default with bazel, to run them :

```bash
bazel test //...
```

## 3.0 Documentation

Documentation is not yet published; API references and examples are in progress.

## 4.0 License  
  
This project is licensed under the MIT license.
see the [LICENSE](./LICENSE) file for more details.
