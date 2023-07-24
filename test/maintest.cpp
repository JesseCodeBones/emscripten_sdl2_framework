#include <gtest/gtest.h>
#include "../include/test.hpp"
TEST(emscripten_sdl2_framework_test, e2e) {
  TestClass t;
  ASSERT_EQ(42, t.returnInt(42));
}