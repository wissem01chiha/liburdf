liburdf
========

[![CMake](https://github.com/wissem01chiha/liburdf/actions/workflows/cmake.yml/badge.svg)](https://github.com/wissem01chiha/liburdf/actions/workflows/cmake.yml)
[![Bazel](https://github.com/wissem01chiha/liburdf/actions/workflows/bazel.yml/badge.svg)](https://github.com/wissem01chiha/liburdf/actions/workflows/bazel.yml)
[![CodeFactor](https://www.codefactor.io/repository/github/wissem01chiha/liburdf/badge)](https://www.codefactor.io/repository/github/wissem01chiha/liburdf)
[![codecov](https://codecov.io/github/wissem01chiha/liburdf/branch/develop/graph/badge.svg?token=1Z4HUX83DE)](https://codecov.io/github/wissem01chiha/liburdf)
[![pre-commit.ci status](https://results.pre-commit.ci/badge/github/wissem01chiha/liburdf/main.svg)](https://results.pre-commit.ci/latest/github/wissem01chiha/liburdf/main)
![GitHub License](https://img.shields.io/github/license/wissem01chiha/liburdf)

liburdf is a modern, cross‑platform C++17 library for reading and writing [urdf](https://industrial-training-master.readthedocs.io/en/melodic/_source/session3/Intro-to-URDF.html) model files, designed to be lightweight, dependency‑free, with multiple language bindings

## About

liburdf is the successor of the tinyurdf project, a lightweight C++17 library for reading and processing urdf model files. I started working on tinyurdf back in 2024 with the goal of providing a replacement for traditional urdf manipulation tools, which rely heavily on the ros runtime, unix dependencies, or small python libraries.

During that time, I faced many issues with closed kinematics tree structures, which existing tools were not friendly with. Visualization and graphical debugging of such models was very painful, not to mention that generating them from mesh or [CAD](https://fileinfo.com/filetypes/cad) files required licensed software with many limitations.

The main goal of liburdf was to provide a free, cross‑platform, lightweight library with multiple language bindings to read, write, generate, and visualize kinematics trees, in a hierarchical xml based representation and convert them back to mesh files.

however, this required a huge amount of work. I re‑uploaded the tinyurdf code under the same license terms with a few enhancements and fixes (hoping it will be useful for some people). The 3D visualization features, which relied heavily on [VTK](https://github.com/Kitware/VTK), has been removed. The focus shifted toward parsing and generation features.

The project was originally derived from [urdf-api](https://docs.ros.org/en/diamondback/api/urdf/html/) and still follows the listed specifications of the urdf file format.

## Platform Support

| Platform | Compiler            | CMake Version |
|----------|---------------------|---------------|
| Windows  | MSVC 2017           | 3.22.1        |
| Linux    | GCC 8               | Latest        |

Other platforms or compilers have not yet been tested. Please open an issue on [GitHub Issues](https://github.com/wissem01chiha/liburdf/issues) for any suspected bugs.

## Quickstart Guide

### CMake

#### Dependencies

liburdf currently depends on the following libraries:

- [TinyXML2](https://github.com/leethomason/tinyxml2)
- [loguru](https://github.com/emilk/loguru)
- [Eigen3](https://eigen.tuxfamily.org)
- [cxxopts](https://github.com/jarro2783/cxxopts)
- [assimp](https://github.com/assimp/assimp)

These are mainly for developers or for building language interfaces:

- [pybind11](https://github.com/pybind/pybind11)
- [googletest](https://github.com/google/googletest)

These dependencies are automatically fetched and compiled during the build process, no separate installation is required.

#### Prerequisites

1. C++17 compatible compiler (GCC 7.1+, Clang 5.0+, MSVC 2017+)
2. CMake (version 3.10+)

#### Configuration Options

| Option                  | Description                           | Default |
|--------------------------|--------------------------------------|---------|
| LIBURDF_BUILD_SHARED     | Build shared library                 | OFF     |
| LIBURDF_BUILD_SCRIPTS    | Enable building C++ scripts          | ON      |
| LIBURDF_ENABLE_TESTING_COVERAGE | Enable Test Coverage          | OFF     |
| LIBURDF_BUILD_TESTS      | Enable building C++ tests            | ON      |
| LIBURDF_BUILD_PYTHON3    | Enable building Python3 binaries     | ON      |
| LIBURDF_INSTALL          | Enable installation of liburdf       | ON      |

#### Build

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

```bash
pip install --user .
```

Note that Python bindings are not currently tested, many bugs exist. Use them at your own risk, or feel free to contribute.

### Bazel

The official build system for liburdf is cmake. However, bazel will continue to be maintained for bazel‑based projects, primarily for integration purposes. Issues may still arise; please report them in the [issue tracker](https://github.com/wissem01chiha/liburdf/issues).

#### Prerequisites

1. C++17 compatible compiler (GCC 7.1+, Clang 5.0+, MSVC 2017+)
2. Bazel (version >=9.0.1)

#### Configuration Options

From the top level of the project folder run

```bash
bazel build //...
```

#### Running Tests

Project tests are built by default with bazel, to run them:

```bash
bazel test //...
```

## API Documentation Reference

Check our [Wiki](https://github.com/wissem01chiha/liburdf/wiki) for detailed documentation and examples.

## FAQ

Have a question? Want some tips? Feel free to join  on  [discussions](https://github.com/wissem01chiha/liburdf/discussions) or open an issue on our [issue tracker](https://github.com/wissem01chiha/liburdf/issues).

## Changelog

See [Changelog](CHANGELOG.md) file for project API changes.

## Support

I'm not planning to actively update the project on a regular basis, but if any critical fixes are contributed, I'll certainly try to review and integrate them.

For bugs, please [report an issue](https://github.com/wissem01chiha/liburdf/issues), submit a [pull request](https://github.com/wissem01chiha/liburdf/pulls) or catch me on [email](mailto:chihawissem08@gmail.com)

Any contributions are greatly appreciated, see [Contributing](.github/CONTRIBUTING.md) for some contribution guidelines.

## Thanks

Many thanks to everyone who has contributed to this project, whether by reporting issues, submitting pull requests, or providing other forms of support. In particular:

- [OmniLink Team](https://github.com/omnilink-tech)
- [Shuyang Liu](https://github.com/kouge0510)

## License

Distributed under the [MIT License](), see [LICENSE](LICENSE.txt) file for more information
