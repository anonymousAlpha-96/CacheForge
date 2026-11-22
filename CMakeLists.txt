cmake_minimum_required(VERSION 3.16)

project(CacheForge
    VERSION 1.0
    DESCRIPTION "In-Memory key-value database"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(cacheforge-server
    src/main.cpp
    src/CacheEngine.cpp
)

target_include_directories(cacheforge-server PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

# GoogleTest dependency
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Unit test executable
add_executable(cacheforge-tests
    tests/CacheEngineTest.cpp
    src/CacheEngine.cpp
)

target_include_directories(cacheforge-tests PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(cacheforge-tests PRIVATE
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(cacheforge-tests)

#GTest ENDS here
