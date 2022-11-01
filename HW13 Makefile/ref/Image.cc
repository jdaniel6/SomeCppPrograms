#include "opengl/Image.hh"

#include <fstream>
#include <string>

#include "glad/glad.h"
#include "opengl/Canvas.hh"
#include <glm/glm.hpp>

#include "util/Ex.hh"
#include "webp/decode.h"
using namespace std;

inline void Image::setupTexture() {
  glGenTextures(1, &textureID);  // generate a single texture in textureId
  glBindTexture(GL_TEXTURE_2D, textureID);  // bind to current texture

  // set texture wrapping to GL_REPEAT (default wrapping method)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  // set texture filtering parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

inline void Image::setupBuffers(float u0, float v0, float u1, float v1) {
  vertices[0] = x;
  vertices[1] = y;
  vertices[2] = u0;
  vertices[3] = v1;

  vertices[4] = x;
  vertices[5] = y + height;
  vertices[6] = u0;
  vertices[7] = v0;

  vertices[8] = x + width;
  vertices[9] = y;
  vertices[10] = u1;
  vertices[11] = v1;

  vertices[12] = x + width;
  vertices[13] = y + height;
  vertices[14] = u1;
  vertices[15] = v0;
}

bool readEntireFile(const char filename[], uint8_t** buf, uint32_t* len) {
  ifstream f(filename);
  f.seekg(0, std::ios::end);  // go to the end
  uint32_t n = f.tellg();     // report location (this is the length)
  *buf = new uint8_t[n];
  f.seekg(0, std::ios::beg);
  f.read((char*)*buf, n);
  *len = n;
  return true;
}

inline void Image::setImage(const char filename[]) {
  uint32_t len;
  uint8_t* p;
  if (!readEntireFile(filename, &p, &len)) throw "error opening file";

  int w, h;
  int status = WebPGetInfo(p, len, &w, &h);
  cout << w << ',' << h << '\n';

  WebPDecoderConfig config;
  if (!WebPInitDecoderConfig(&config)) throw "cannot initialize config";
  if (WebPGetFeatures(p, len, &config.input) != VP8_STATUS_OK)
    throw "cannot get features";
  const uint32_t SIZE = w * h * 4;
  // Specify the desired output colorspace:
  config.output.colorspace = MODE_RGBA;
  config.output.is_external_memory = 1;
  // Have config.output point to an external buffer:
  uint8_t* data = new uint8_t[SIZE];  // allocate memory
  if (data == nullptr) throw Ex2(Errcode::IMAGE_LOAD, filename);
  config.output.u.RGBA.rgba = data;
  config.output.u.RGBA.stride = w * 4;  // scanline_stride;
  config.output.u.RGBA.size = SIZE;

  int err = 0;
  if ((err = WebPDecode(p, len, &config)) != VP8_STATUS_OK) {
    std::cerr << "WebPDecode error " << err << '\n';
    throw "webp corrupt";
  }

  for (int i = 3; i < config.output.u.RGBA.size; i+=4) {
    data[i] = 200;
    // cout << data[i] << ' ';
  }

   for (int i = 0; i < log2(config.output.u.RGBA.size); i++) {
    // data[i] = 50;
    cout << (int)data[i] << ' ';
  }

  // generate texture and bind it to current object
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureWidth, textureHeight, 0, GL_RGBA,
               GL_UNSIGNED_BYTE, data);
  glGenerateMipmap(GL_TEXTURE_2D);
  delete[] data;
}

Image::Image(float x, float y, float width, float height, uint32_t textureID)
    : x(x), y(y), width(width), height(height), textureID(textureID) {
  setupBuffers(0, 1, 1, 0);
}

Image::Image(float x, float y, float width, float height, const char filePath[])
    : x(x), y(y), width(width), height(height) {
  setupBuffers(0, 1, 1, 0);
  setupTexture();
  setImage(filePath);
}

void Image::init() {
  glGenVertexArrays(1, &vao);  // Creating rect VAO
  glBindVertexArray(vao);

  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);

  // position attribute
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
  // texture coord attribute
  glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_FALSE, 4 * sizeof(uint8_t),
                        (void*)(2 * sizeof(uint8_t)));
}

void Image::render(glm::mat4& proj) {
  glBindVertexArray(vao);
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);

  Shader* s = Shader::useShader(GLWin::TEXTURE_SHADER);
  s->setMat4("projection", proj);
  s->setInt("ourTexture", 0);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, textureID);

  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  glDisableVertexAttribArray(1);
  glDisableVertexAttribArray(0);
  glBindVertexArray(0);
}

void Image::update() {}

void Image::cleanup() { glDeleteTextures(1, &textureID); }