---
title: User's Guide
nav_order: 1
---

# Liburdf User's Guide

## Welcome to Liburdf !


liburdf is the successor of the tinyurdf project, a lightweight C++17 library for reading and processing urdf model files. I started working on  tinyurdf back in 2024 with the goal of providing a replacement for traditional urdf manipulation tools, which rely heavily on the ros runtime, unix dependencies, or small python libraries.  

During that time, I faced many issues with closed kinematics tree structures, which existing tools were not friendly with. Visualization and graphical debugging of such models was very painful, not to mention that generating them from mesh or [CAD](https://fileinfo.com/filetypes/cad) files required licensed software with many limitations.  

The main goal of liburdf was to provide a free, cross‑platform, lightweight library with multiple language bindings to read, write, generate, and visualize kinematics trees, in a hierarchical xml based representation and convert them back to mesh files

however, this required a huge amount of work. I re‑uploaded the tinyurdf code under the same license terms with a few enhancements and fixes (hoping it will be useful for some people). The 3D visualization features, which relied heavily on [VTK](https://github.com/Kitware/VTK), has been removed. The focus shifted toward parsing and generation features.

The project was originally derived from [urdf-api](https://docs.ros.org/en/diamondback/api/urdf/html/) and still follows the listed specifications of the urdf file format.


This user's guide has the following contents:

*   [quickstart cmake](quickstart-cmake.md) - Step by step guide to build and run liburdf using cmake build system 
*   [quickstart bazel](quickstart-bazel.md) - Step by step guide to build and run liburdf using bazel build system
*   [liburdf examples](./examples.md) - Describes some liburdf samples.
*   [liburdf changelog](./changelog.md) - Project API Changes reference 
*   [pkgconfig integration](pkgconfig.md) - Set up liburdf with pkgconfig tool in cmake  
*   [liburdf FAQ](faq.md) - Have a question? Want some tips? Check here
    first.

