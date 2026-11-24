
##########################################################################################################
#copyright (c) 2026 reserved
#Author: Ankit
#Date: 2026/24/11
#Description: CMakeLists.txt for CacheForge project
##########################################################################################################
#=========================================================================================================
# 21-Nov-26 : Task 01 : Created CMakeLists.txt & initial commits 
#=========================================================================================================
# 24-Nov-26 :Task 02 : Updated CMakeLists.txt to include new src files & clean-all commands
#=========================================================================================================

cmake_minimum_required(VERSION 3.16)

project(CacheForge
    VERSION 1.0
    DESCRIPTION "In-Memory key-value database"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
    COMMENT "Cleaning CacheForge build artifacts"
)

add_executable(cacheforge-server
    src/main.cpp
    src/CacheEngine.cpp
    src/commandProcessor.cpp
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
    src/commandProcessor.cpp
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
