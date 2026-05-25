# Tutorials

At the moment, the available documentation does not provide extensive examples.

- Additional test scripts, which may be useful, can be found in the [test](/test/) folder.  
- Samples of model files can be found in the [urdf](examples/urdf/) directory. These files are mainly sourced from the [urdf_files_dataset](https://github.com/Daniella1/urdf_files_dataset).

The examples assume that all installation instructions have been followed and that the library is successfully installed.

#### Example 1: Parsing an URDF File

```cpp
#include "tinyurdf/tinyurdf.h"  

int main() {
  // Create the parser
  URDFParser parser;  
  // Parse the file
  parser.parse("path/to/tinyurdf/examples/urdf/example.urdf");  
  // Get the model 
  std::shared_ptr<Model> model_ = parser.get(); 
  // Print the model info  
  std::cout << model_->toString();
  return 0;
}
```
This will print all model data to the standard output without any formatting or adjustments.

Alternatively, when -DBUILD_SCRIPTS is enabled, you can parse the files from the command line as shown below:

```bash
./urdf_parse --file path/to/your/urdf_model.urdf
```

#### Example 2: Get Multijoint Model Data

```cpp
#include "tinyurdf/tinyurdf.h"  

int main() {
  // Construct the parser
  URDFParser parser; 
  // Call the parsing routine 
  parser.parse("path/to/file.urdf");
  // Get the model 
  std::shared_ptr<Model> model_ = parser.get();  
  // Get the model name 
  std::string name = model_->getName(); 
  // Get model joints
  std::vector<std::shared_ptr<Joint>> joints_ = model_->getJoints();
  // Get model links 
  std::vector<std::shared_ptr<Link>> links_ = model_->getLinks();
  // Check whether the model is empty 
  bool status = model_->empty();
  return 0;
}
```
#### Python Interface Example
Here is an example of the Python interface, which is similar to the C++ interface:

```python
from pytinyurdf import pyurdf_parser

def main():
    parser = pyurdf_parser.URDFParser()
    urdf_file = "spot.urdf"
    parser.parse(urdf_file)
    model = parser.get()
    print(model.getName())
    print(model.__str__())

if __name__ == "__main__":
    main()
```

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

for gtest installation : https://gist.github.com/Cartexius/4c437c084d6e388288201aadf9c8cdd5?permalink_comment_id=2822039#gistcomment-2822039

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

https://github.com/llvm/llvm-project/releases/tag/llvmorg-16.0.0

