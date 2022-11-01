#ifndef GLYPH_H
#define GLYPH_H
#include <cstdint>

class bitmap;

class glyph
{
private:
  uint32_t width;  // width of the pixels of the char itself
  uint32_t height; // height of the pixels of the char itself
  uint32_t advance; // width + spacing to get to start of next char
  uint32_t bearingX; // delta from start point to left edge of char
  uint32_t bearingY; // delta from start point to top edge of char
  uint32_t offset;   // relative location of 64-bit word containg bits within font

public:
  glyph(uint32_t width, uint32_t height,
        uint32_t advance,
        uint32_t bearingX, uint32_t bearingY,
        uint32_t offset);

 void render(bitmap& bm, uint32_t x, uint32_t y);

};

#endif

