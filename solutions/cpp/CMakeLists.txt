cmake_minimum_required (VERSION 3.10)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(fmt)

# add_executable(1two_sum ./1two-sum.cpp)
# target_link_libraries(1two_sum fmt::fmt)
include_directories(include)

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main
)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_subdirectory(tests)
