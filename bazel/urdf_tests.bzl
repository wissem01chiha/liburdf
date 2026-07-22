# SPDX-FileCopyrightText: 2024-2026 Wissem Chiha
# SPDX-License-Identifier: MIT

"""Starlark macros for URDF test configuration."""

load("@rules_cc//cc:cc_test.bzl", "cc_test")


def urdf_tests(test_files):
    for f in test_files:
        name = f.split(":")[-1].replace(".cc", "")
        cc_test(
            name = name,
            srcs = [f],
            deps = [
                "//:liburdf",
                "@gtest//:gtest_main",
            ],
            data = [
                "//test:assets"],
        )
