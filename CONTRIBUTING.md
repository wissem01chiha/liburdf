# Contribution Guide

Discussion about liburdf happens on GitHub and on [slack](https:://liburdf.slack.com/) channel

- GitHub [wissem01chiha/liburdf](https://github.com/wissem01chiha/liburdf/discussions)
- Slack  [slack-liburdf](https:://liburdf.slack.com/)

If you have any questions or need clarification, feel free to [email me](mailto:chihawissem08@gmail.com).

Thank you for contributing !

## Contribution guidelines and standards

### General Guidelines

- Include unit tests when you contribute new features, as they help prove that your code works correctly and guard against future breaking changes, reducing maintenance costs.
- Use the minimal number of header includes as possible in *.h or *.cc files, as it significantly reduces compiler time.
- Follow file naming conventions: `.h` for headers and `.cc` for implementations.
- The `common/` folder should contain only interfaces or shared code.
- Try to stay highly modular with a focus on polymorphism.
- Tests should use only the [Google Test](https://google.github.io/googletest/) framework and depend only on minimal library files. Avoid including umbrella or unnecessary includes in test sources.

### C++ Code Style

We generally follow the [Google Style Guide](https://google.github.io/styleguide/). Currently, there is no automated checking pipeline for this, but I will personally review the code. Contributions to add such a pipeline would be highly appreciated.

### License

- Include a license at the top of new files.

## Pull Request Checklist


## Notes

- The current version parses and renders model joints, links, and visual elements. Other elements, such as transmissions and sensors, will be supported in future releases.
- Physical consistency verification (e.g., inertia values) is not activated by default.
- The `COLLADA` file format for links' visual or collision meshes is not yet supported. Only `STL` and `STEP` files are handled; other CAD file formats will be added progressively.
- Multi-model handling, model interactions, and world parsing are not yet supported.
- File paths should be absolute. Relative paths are not currently supported.


## Current Tasks

Here are some key tasks where contributions are needed:

- Complete the implementation of the [urdf-graphiz](scripts/src/urdf-to-graphiz.cc) interface.
- Complete the development of core modules:
- [camera](include/tinyurdf/core/camera.h)
- [camera_parser](include/tinyurdf/internal/camera_parser.h)
- Add support for transmission parsing.
- Add graph computation functions (e.g., computing model roots, leaves, etc.).
- Implement utility functions for inertial, volume, and collision computations, such as:
- Total mass
- Center of inertia
- Total volume of the model
- Density, and more
- Precomputed Forward Kinematics
- Bounding Volume Hierarchy (BVH) for fast collision detection

## Additional Features

These additional features would improve the library:

- Add a custom project logo.
- Create a pipeline to deploy the library upon each release to the **vcpkg** package manager.
- Check/test the [docker](./Dockerfile) pipeline build status and create a custom workflow.