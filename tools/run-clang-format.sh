#!/bin/bash
# -----------------------------------------------------------------------------
# run-clang-format.sh
#
# This file is part of the liburdf library.
#
# Copyright 2024-2026, Wissem CHIHA.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
# -----------------------------------------------------------------------------

set -e

COLOR_OFF="\033[0m"
RED="\033[0;31m"

fatal() {
    echo -e >&2 "${RED}[FATAL] : $*${COLOR_OFF}"
    exit 1
}

# check if clang-format is available.
if command -v clang-format >&2; then
  version=$(clang-format --version)
  echo clang-format "${version}"
else
  echo clang-format is not found
fi

# this script should be run from the top-level repository,
# where the .git folder of the mio project is located.
repo_root=pwd

# using mapfile to iterate safely over the files 
mapfile -t includes < <(find ./include/urdf -type f -name "*.h")
mapfile -t sources  < <(find ./src -type f -name "*.cc")
mapfile -t tests    < <(find ./test -type f -name "*.cc")
mapfile -t scripts    < <(find ./scripts/src -type f -name "*.cc")

for file in "${sources[@]}"; do
    clang-format -i -style=file "$file"
done

for file in "${includes[@]}"; do
    clang-format -i -style=file "$file"
done

for file in "${tests[@]}"; do
    clang-format -i -style=file "$file"
done

for file in "${scripts[@]}"; do
    clang-format -i -style=file "$file"
done