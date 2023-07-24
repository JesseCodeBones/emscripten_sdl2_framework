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

file(GLOB sources CONFIGURE_DEPENDS ../src/*.cpp ../src/*.hpp)
target_sources(emscripten_sdl2_framework_test PUBLIC ${sources})
include(GoogleTest)
gtest_discover_tests(emscripten_sdl2_framework_test)