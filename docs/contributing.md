---
title: Contribution Guide
nav_order: 5
---

# Contribution Guide

Due to time constraints, I am unable to maintain this project constantly. However, the work is in progress, and any contributions are greatly appreciated.  
Please feel free to open an [issue](https://github.com/wissem01chiha/liburdf/issues). I will try to address any concerns as best I can.
Please refer to the following guidelines for areas where help is needed:

## General Guidelines

- Use the minimal header includes as possible.
- Follow file naming conventions `.h` for headers and `.cc` for implementations
- The `common/` folder should contain only interfaces or shared code.
- Try to be highly modular with a focus on polymorphism.
- Avoid using Boost libraries wherever possible.

## Notes

- The current version parses and renders model joints, links, and visual elements. Other elements like transmissions and sensors will be supported in future releases.
- Physical consistency verification (e.g., inertia values) is not activated by default.
- A scaling issue may occur during rendering due to element marker sizes.
- The `COLLADA` file format for links' visual or collision meshes is not yet supported. Only `STL` files, `STEP` will be handled, other `CAD` file format, will be added progressivlly
- Multi-model handling, model interactions, and world parsing are not yet supported.
- File paths should be absolute. Relative paths are not currently supported.

## Style

We generally follow the [Google Style Guide](https://google.github.io/styleguide/). Currently, there is no automated checking pipeline for this, but I will personally review the code. Contributions to add such a pipeline would be highly appreciated.

---

## Current Tasks

Here are some key tasks where contributions are needed:

- [ ] Complete the implementation of the [urdf-graphiz](scripts/src/urdf-to-graphiz.cc) interface.
- [ ] Complete the development of core modules:
  - [camera](include/tinyurdf/core/camera.h)
  - [camera_parser](include/tinyurdf/internal/camera_parser.h)
- [ ] Add support for transmission parsing.
  - Complete the implementation of [internal_graph](include/tinyurdf/detail/internal_graph.h) module

- [ ] Add [Collada](https://en.wikipedia.org/wiki/COLLADA) file support using the [collada-dom](https://github.com/rdiankov/collada-dom) library.
- [ ] Ensure each implementation is tested in the [test](test/) folder.
- [ ] Add graph computation functions (e.g., computing model roots, leaves, etc.).
- [ ] Implement utility functions for inertial, volume, and collision computations, such as:
  - Total mass
  - Center of inertia
  - Total volume of the model
  - Density, and more
  - Precomputed Forward Kinematics
  - Bounding Volume Hierarchy (BVH) for fast collision detection
  
---

## Additional Features

These additional features would improve the library:

- [ ] Add a custom project logo.
- [ ] Create a pipeline to deploy the library upon each release to **vcpkg** package manager.
- [ ] Check/test the [docker](./Dockerfile) pipeline build status and create a custom workflow.

---

If you have any questions or need clarification, feel free to [email me](mailto:chihawissem08@gmail.com).

Thank you for contributing!

Ressources
=====

- [stl_reader-documentation](https://sreiter.github.io/stl_reader/stl__reader_8h.html)
- [pybind11-documentation](https://pybind11.readthedocs.io/en/stable/)
- [urdfdom-debian-package](https://docs.ros.org/en/diamondback/api/urdf/html/index.html)
- [urdf-ros-wiki](https://wiki.ros.org/urdf)
  
## Related Projects

- [urdf-vis](https://github.com/openrr/urdf-viz)
- [urdf-importer](https://github.com/Unity-Technologies/URDF-Importer)
- [related-ressources](https://stevengong.co/notes/URDF)

How to install Ninja  

- **On Windows** (via Chocolatey):  

  ```bash
  choco install ninja
  ```

- **On linux**

  ```bash
  sudo apt-get install ninja-build

 ```

How to install VCPKG
----

Official Link: <https://vcpkg.io/en/index.html>

```cmd
cd external
git clone https://github.com/Microsoft/vcpkg.git
.\vcpkg\bootstrap-vcpkg.bat # windows
./vcpkg/bootstrap-vcpkg.sh # Unix
```

How to install Google Test on ubuntu
----

for gtest installation : <https://gist.github.com/Cartexius/4c437c084d6e388288201aadf9c8cdd5?permalink_comment_id=2822039#gistcomment-2822039>

```cmd
sudo apt-get install libgtest-dev
cd /usr/src/googletest/googletest
sudo mkdir build
cd build
sudo cmake ..
sudo make
sudo cp lib/libgtest* /usr/lib/
cd ..
sudo rm -rf build
```

Then do:

```cmd
sudo mkdir /usr/local/lib/googletest
sudo ln -s /usr/lib/libgtest.a /usr/local/lib/googletest/libgtest.a
sudo ln -s /usr/lib/libgtest_main.a /usr/local/lib/googletest/libgtest_main.a
```

## Formatter and Static Analyzer

### Tooling

Clang-Format: Formatting tool for your C/C++ code:

- Documentation for Clang-Format: [Link](https://clang.llvm.org/docs/ClangFormat.html)

Clang-Tidy: Static linting tool for your C/C++ code:

- Documentation for Clang-Tidy: [Link](https://clang.llvm.org/extra/clang-tidy/)

Cmake-Format:

```bash
pip install cmake-format # python 3.7+
```

### Coverage Tools

```bash
sudo apt-get install gcovr
pip install -U gcovr
```

### Install Clang Tools

It's included in the LLVM toolchain, but also installable by apt, brew, winget etc.

<https://github.com/llvm/llvm-project/releases/tag/llvmorg-16.0.0>
