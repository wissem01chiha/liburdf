---
title: Quickstart - Bazel
nav_order: 5
---

# Quickstart Guide - Bazel 

The official build system for liburdf is cmake. however, bazel will continue to be maintained for bazel‑based projects, primarily for integration purposes.Issues may still arise; please report them in the [issue tracker](https://github.com/wissem01chiha/liburdf/issues).


## Prerequisites

1. C++17 compatible compiler (GCC 7.1+, Clang 5.0+, MSVC 2017+)
2. Bazel (version >=9.0.1)
  
## Configuration Options

From the top level of the project folder run 

```bash
bazel build //...
```

## Running Tests 

Project tests are build by default with bazel, to run them :

```bash
bazel test //...
```