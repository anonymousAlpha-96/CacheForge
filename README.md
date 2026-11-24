
**build project**
- cmake -S . -B build
- cmake --build build

**execute cacheforge-server**
- ./build/cacheforge-server

**execute cacheforge-test**
- ./build/cacheforge-tests 

**clean-all**
-cmake --build build --target clean-all
