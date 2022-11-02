#pragma once

#include <vector>
#include <string>
#include "font.hh"
/**
 * Represent a family of fonts of different sizes
 * THe size is the vertical height of the font
*/
class font_face {
private:
  std::vector<font> fonts;
  std::string filename;
public:
  font_face(std::string filename);
  const font* get(std::string facename, uint32_t size) const;
};
