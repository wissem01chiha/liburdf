:: -----------------------------------------------------------------------------
:: run-clang-format.bat
::
:: This file is part of the liburdf library.
::
:: Copyright 2024-2026, Wissem CHIHA.
::
:: Permission is hereby granted, free of charge, to any person obtaining a copy
:: of this software and associated documentation files (the "Software"), to deal
:: in the Software without restriction, including without limitation the rights
:: to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
:: copies of the Software, and to permit persons to whom the Software is
:: furnished to do so, subject to the following conditions:
::
:: The above copyright notice and this permission notice shall be included in all
:: copies or substantial portions of the Software.
::
:: THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
:: IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
:: FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
:: AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
:: LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
:: OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
:: SOFTWARE.
:: -----------------------------------------------------------------------------
@echo off
SETLOCAL enableDelayedExpansion

:: Full path for the clang-format executable, useful when the clang-format
:: folder is not added, or cannot be added, to the system PATH. modify
:: this path according to your setup.
set CLANG_FORMAT="C:\Program Files\LLVM\bin\clang-format.exe"

:: Check if clang-format is available in the system PATH.
:: If not found, fall back to the full path location.
:: If neither is available, output an error and exit.
where clang-format.exe > NUL 2>&1
if %ERRORLEVEL% EQU 0 (
    set "CLANG_FORMAT=clang-format.exe"
) else (
    if not exist %CLANG_FORMAT% (
        echo clang-format.exe not found in PATH or at %CLANG_FORMAT%
        exit /b 1
    )
)

:: Note: this script should be run from the top-level repository,
:: where the .git folder of the mio project is located.
set REPO_ROOT=%CD%

for /R "%REPO_ROOT%\include\urdf" %%f in (*.h) do (
    %CLANG_FORMAT% -i -style=file "%%f"
)

for /R "%REPO_ROOT%\src" %%f in (*.cc) do (
    %CLANG_FORMAT% -i -style=file "%%f"
)

for %%f in ("%REPO_ROOT%\test\*.cc") do (
    %CLANG_FORMAT% -i -style=file "%%f"
)

