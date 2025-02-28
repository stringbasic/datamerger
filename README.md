[![Build Status](https://github.com/stringbasic/datamerger/workflows/CI/badge.svg)](https://github.com/stringbasic/datamerger/actions)
[![Total alerts](https://img.shields.io/lgtm/alerts/g/stringbasic/datamerger.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/stringbasic/datamerger/alerts/)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/stringbasic/datamerger.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/stringbasic/datamerger/context:cpp)

# datamerger
Multiple sources data merger

# To compile and test

## Pull submodules
```
git submodule update --init --recursive
```

## build the project
```
cmake . -Bbuild
cmake --build build
```

## Run tests
```
make -C build/ test
```

## Configure compile commands
```
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -S . -B build
```