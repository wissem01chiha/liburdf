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

  ``LIBURDF_INCLUDE_DIR``
    The directory containing the liburdf headers.

  ``LIBURDF_LIBRARIES``
    The liburdf libraries to link against.

  ``LIBURDF_LIBRARY_VERSION``
    The liburdf library to link against in release builds.

  ``LIBURDF_FOUND``
    True if the liburdf library was found.
#]=======================================================================]