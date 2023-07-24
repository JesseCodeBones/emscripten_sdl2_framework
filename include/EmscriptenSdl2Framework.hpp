
#pragma once
#include <GLES2/gl2.h>
#include <SDL2/SDL.h>
#include <functional>
#ifdef __EMSCRIPTEN__
#include "emscripten/emscripten.h"
#endif
class EmscriptenSdl2Framework {
public:
  static GLuint compileShader(GLenum type, const char *source);
  EmscriptenSdl2Framework(std::function<void()> &init, std::function<void()> &render,
                          std::function<void()> &clear) noexcept
      : init_(init), render_(render), clear_(clear) {
  }

  void run() {
    // SDL init
    init_();

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(wasmLoop, 100, 1);
#else
    bool quit = false;
    while (!quit) {
      quit = loop();
    }
#endif
    clear_();
  }

private:
  std::function<void()> &init_;
  std::function<void()> &render_;
  std::function<void()> &clear_;
  bool loop();
  void wasmLoop();
};
