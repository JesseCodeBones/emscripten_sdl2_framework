find_package(GTest REQUIRED)
file(GLOB test_sources CONFIGURE_DEPENDS ./*.cpp)
add_executable(
  emscripten_sdl2_framework_test
  ${test_sources}
)

target_link_libraries(
  emscripten_sdl2_framework_test
  GTest::gtest_main
)

file(GLOB sources CONFIGURE_DEPENDS ../src/*.cpp ../include/*.hpp)
target_sources(emscripten_sdl2_framework_test PUBLIC ${sources})
include(GoogleTest)
gtest_discover_tests(emscripten_sdl2_framework_test)

if(CMAKE_COMPILER_IS_GNUCXX)
  LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
  include(CodeCoverage)
  APPEND_COVERAGE_COMPILER_FLAGS()
  setup_target_for_coverage_gcovr_xml(NAME cov
                            EXECUTABLE emscripten_sdl2_framework_test
                            DEPENDENCIES emscripten_sdl2_framework_test
                            EXCLUDE "${PROJECT_SOURCE_DIR}/test/*"
                            BASE_DIRECTORY "${PROJECT_SOURCE_DIR}")

  setup_target_for_coverage_gcovr_html(NAME cov_html 
                            EXECUTABLE emscripten_sdl2_framework_test
                            DEPENDENCIES emscripten_sdl2_framework_test
                            EXCLUDE "${PROJECT_SOURCE_DIR}/test/*"
                            BASE_DIRECTORY "${PROJECT_SOURCE_DIR}") 
endif()