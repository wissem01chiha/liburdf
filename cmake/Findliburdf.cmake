# SPDX-FileCopyrightText: 2024-2026 Wissem Chiha
# SPDX-License-Identifier: MIT
#[=======================================================================[.rst:
Findliburdf
-----------
Find the liburdf library
.. code-block:: cmake

  find_package(liburdf [<version>] [...])

Imported Targets
^^^^^^^^^^^^^^^^

The following targets are imported into the project:

    - ``urdf::urdf``

Result Variables
^^^^^^^^^^^^^^^^
This module defines the following variables:

  ``URDF_INCLUDE_DIR``
    The directory containing the liburdf headers.

  ``URDF_LIBRARY``
    The liburdf library to link against.

  ``URDF_LIBRARIES``
    The liburdf libraries to link against.

  ``URDF_LIBRARY_DEBUG``
    The liburdf library to link against in debug builds.

  ``URDF_LIBRARY_RELEASE``
    The liburdf library to link against in release builds.

  ``URDF_FOUND``
    True if the liburdf library was found.

  ``URDF_VERSION``
    The version of the liburdf library found.
#]=======================================================================]