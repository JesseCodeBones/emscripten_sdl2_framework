cmake_minimum_required(VERSION 3.0.0)
project(emscripten_sdl2_framework VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_library(emscripten_sdl2_framework emscripten_sdl2_framework.cpp)

add_subdirectory(test)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
