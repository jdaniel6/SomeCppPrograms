#ifndef FONT_HH_
#define FONT_HH_

#include <vector>
#include "glyph.hh"

/**
 * Read in font using freetype library into a single block of memory
 * This is slow because freetype uses many individual calls
 * If we have time, rewrite this one to read the font in a single block
 * operation (font, next)
*/
class font {
private:
  std::vector<glyph> glyphs;
  uint64_t* bits;

public:
  font(const char filename[]);
  ~font();

  uint32_t width(const char text[], uint32_t len);
};

#endif