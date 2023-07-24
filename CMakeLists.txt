cmake_minimum_required(VERSION 3.0.0)
project(emscripten_sdl2_framework VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
if(ENABLE_CLANG_TIDY)
  set(CMAKE_CXX_CLANG_TIDY clang-tidy -extra-arg=-std=gnu++${CMAKE_CXX_STANDARD} --config-file ${CMAKE_CURRENT_SOURCE_DIR}/.clang-tidy --header-filter=${CMAKE_CURRENT_SOURCE_DIR}/[src|test]*.*hpp)
  if(ENABLE_WERROR)
      set(CMAKE_CXX_CLANG_TIDY ${CMAKE_CXX_CLANG_TIDY} -warnings-as-errors=*)
  endif()
endif()
add_library(emscripten_sdl2_framework emscripten_sdl2_framework.cpp)
add_subdirectory(test)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
