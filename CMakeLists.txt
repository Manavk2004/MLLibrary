cmake_minimum_required(VERSION 3.20)
project(kensor VERSION 0.1.0 LANGUAGES CXX)


# ----- Language standard -------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- The library itself ------------------------
add_library(kensor INTERFACE)
target_include_directories(kensor INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(MSVC)
    target_compile_options(kensor INTERFACE /W4)
else()
    target_compile_options(kensor INTERFACE -Wall -Wextra -Wpedantic)
endif()

# --- Test framework: doctest, vendored single header in third_party/ ------
enable_testing()
add_executable(kensor_tests
    tests/test_sanity.cpp
)

target_link_libraries(kensor_tests PRIVATE kensor)
target_include_directories(kensor_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/third_party)
add_test(NAME kensor_tests COMMAND kensor_tests)