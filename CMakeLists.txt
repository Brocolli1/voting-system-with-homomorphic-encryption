### simplified copy of the CMakeLists.txt file of the HElib examples
cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)
## Use -std=c++17 as default.
set(CMAKE_CXX_STANDARD 17)
## Disable C++ extensions
set(CMAKE_CXX_EXTENSIONS OFF)
## Require full C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(HELibDemo VERSION 1.0)
add_executable(init init.cpp)
add_executable(encrypt encrypt.cpp)
add_executable(decrypt decrypt.cpp)
add_executable(sum sum.cpp)
find_package(helib ${HELIB_VERSION} REQUIRED)
target_link_libraries(init helib)
target_link_libraries(encrypt helib)
target_link_libraries(decrypt helib)
target_link_libraries(sum helib)