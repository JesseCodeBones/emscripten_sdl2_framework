#include "../include/EmscriptenSdl2Framework.hpp"
#include <cstdio>

GLuint EmscriptenSdl2Framework::compileShader(GLenum type, const char *source) {
  GLuint shader = glCreateShader(type);
  glShaderSource(shader, 1, &source, nullptr);
  glCompileShader(shader);

  GLint success;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (0 == success) {
    char infoLog[512]; // NOLINT(modernize-avoid-c-arrays)
    glGetShaderInfoLog(shader, sizeof(infoLog), nullptr, infoLog);
    printf("Shader compilation failed:\n%s\n", infoLog); // NOLINT(cppcoreguidelines-pro-type-vararg)
    printf("%s\n", source); // NOLINT(cppcoreguidelines-pro-type-vararg)
    glDeleteShader(shader);
    return 0;
  }
  return shader;
}

bool EmscriptenSdl2Framework::loop() {
  bool quit = false;
  SDL_Event event;
  while (SDL_PollEvent(&event) != 0) {
    if (event.type == SDL_QUIT) {
      quit = true;
#ifdef __EMSCRIPTEN__
      emscripten_cancel_main_loop();
#endif
    }
  }
  this->render_();
  return quit;
}
void EmscriptenSdl2Framework::wasmLoop() { loop(); }