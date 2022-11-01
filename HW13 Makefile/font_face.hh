#pragma once

#include <vector>
#include "font.hh"
/**
 * Represent a family of fonts of different sizes
 * THe size is the vertical height of the font
*/
class font_face {
private:
  std::vector<font> fonts;
public:
  font_face(const char filename[]);
  const font* get(const char faceName[], uint32_t size);
};
