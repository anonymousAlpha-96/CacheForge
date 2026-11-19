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
