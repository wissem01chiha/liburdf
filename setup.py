#!/usr/bin/env python

# SPDX-FileCopyrightText: 2024-2026 Wissem Chiha
# SPDX-License-Identifier: MIT

from setuptools import setup

setup(
    name="liburdf",
    version="0.1.0",
    author="Wissem CHIHA",
    description= "URDF File I/O Library",
    url="https://github.com/wissem01chiha/liburdf",
    packages=["pyliburdf"],
    package_dir={"pyliburdf": "build/python"},
    py_modules=["pyliburdf", "pyurdf_parser"],
    package_data={
        "pyliburdf": ["*.pyd"]  
    },
    include_package_data=True
)
