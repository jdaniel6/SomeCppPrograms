#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

class color {
private:
  uint32_t val;
public:
  color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {}
  color(uint8_t rgba) : val(rgba) {}
  color darker() const {
    return color(0); //TODO: implement
  }
  color lighter() const {
    return color(0); //TODO: implement
  }
	static color RED, GREEN, BLUE, WHITE, BLACK, YELLOW, PINK;
  friend std::ostream& operator <<(std::ostream& s, const color c) {
    //TODO: print out color in hex: r=hh g=hh b=hh a=hh
    return s;
  }
};
		
color color::RED = {0xFF0000FF};
color color::GREEN = {0x00FF00FFU};
color color::BLUE = {0x0000FFFFU};
color color::WHITE = {0xFFFFFFFFU};
color color::BLACK = {0x00000000U};
color color::YELLOW = {0xFFFF00FFU};
color color::PINK = {0xFF00FFFFU};

	
class font;

class bound_box {
public:
  uint32_t x, y, w, h;
  bound_box(uint32_t x, uint32_t  y, uint32_t  w, uint32_t h) 
  : x(x), y(y), w(w), h(h) {}
  bound_box inset(uint32_t in) const {
    return bound_box(x + in, y + in, w - 2*in, h - 2*in);
  }
};


/**
 * Represent a bitmap where each pixel is a 32-bit number containing
 * RGBA (red, green, blue, alpha) 8-bits each
 * TODO: define, probably little-endian
 */
class bitmap {
private:
  uint32_t* pixels;
  uint32_t w,h; // size of image
public:
  bitmap(uint32_t w, uint32_t h);
  ~bitmap();

  // we won't support copying bitmaps yet
  bitmap(const bitmap& orig) = delete;
  bitmap& operator =(const bitmap& orig) = delete;

  // read/write a single pixel
  uint32_t& operator ()(uint32_t x, uint32_t y) {
    return pixels[y * w + x];
  }
  // readonly lookup a single pixel
  uint32_t operator ()(uint32_t x, uint32_t y) const {
    return pixels[y * w + x];
  }

  // draw horizontal line from (x1,y) to (x2,y)
  // note this can be significantly faster than arbitrary diagonals
  void horiz_line(uint32_t x1, uint32_t x2, uint32_t y, color c);

  // draw vertical line from (x,y1) to (x,y2)
  // note this can be significantly faster than arbitrary diagonals
  void vert_line(uint32_t x, uint32_t y1, uint32_t y2, color c);

  // draw an arbitrary diagonal line from (x1,y1) to (x2,y2) in color c
  // see Bresenham algorithm in wikipedia
  void line(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, color c);

  void rect(uint32_t x1, uint32_t y1, uint32_t w, uint32_t h, color c));
  void fill_rect(uint32_t x1, uint32_t y1, uint32_t w, uint32_t h, color c));

  void circle(uint32_t xc, uint32_t yc, uint32_t r, color c));
  void fill_circle(uint32_t xc, uint32_t yc, uint32_t r, color c));

  void ellipse(uint32_t xc, uint32_t yc, uint32_t r, color c));
  void fill_ellipse(uint32_t xc, uint32_t yc, uint32_t rx, uint32_t ry, color c));
  void grid(uint32_t x, uint32_t y, uint32_t dx, uint32_t dy,
   uint32_t num_rows,  uint32_t num_cols);
  void gouraud(uint32_t x1, uint32_t y1, color c1,
                uint32_t x2, uint32_t y2, color c2,
                uint32_t x3, uint32_t y3, color c3);
  void triangle(uint32_t x1, uint32_t y1,
                uint32_t x2, uint32_t y2,
                uint32_t x3, uint32_t y3, color c);
  void quad(uint32_t x1, uint32_t y1,
            uint32_t x2, uint32_t y2,
            uint32_t x3, uint32_t y3,
            uint32_t x4, uint32_t y4,
            color c);
  void fill_quad(uint32_t x1, uint32_t y1,
            uint32_t x2, uint32_t y2,
            uint32_t x3, uint32_t y3,
            uint32_t x4, uint32_t y4,
            color c);
  void fill_quad(uint32_t x1, uint32_t y1, color c1,
            uint32_t x2, uint32_t y2, color c2,
            uint32_t x3, uint32_t y3, color c3,
            uint32_t x4, uint32_t y4, color c4);
  void fill_grid(uint32_t x[], uint32_t xlen,
                 uint32_t y[], uint32_t ylen, 
                 float data[]);
  // draw a cubic bezier curve
  //TODO: specify the resolution of the line segments?
  void bezier(float x0, float y0,
              float x1, float y1,
              float x2, float y2,
              float x3, float y3,
              color c);
  // draw a sequence of connected cubic beziers where
  // the first point of each is the last of the previous
  void bezier(float pts[], uint32_t len, color c);

  // piecewise cubic hermite interpolation
  // see: https://www.mathworks.com/help/matlab/ref/pchip.html
  void pchip(float x0, float y0,
              float x1, float y1,
              float x2, float y2,
              float x3, float y3,
              color c);
  void lagrange(float x0, float y0,
                float x1, float y1,
                float x2, float y2,
                float x3, float y3, color c);
  

  void natural_spline(float pts[], uint32_t len, color c);

  void text(uint32_t x, uint32_t y, const font* f, const char text[], uint32_t len);

  // inline convenience function for nul-terminated strings
  void text(uint32_t x, uint32_t y, const font* f, const char text[]) {
    text(x, y, f, text, strlen(text));
  }
  void text(uint32_t x, uint32_t y, const font* f, uint32_t val);
  void text(uint32_t x, uint32_t y, const font* f, uint64_t val);
  void text(uint32_t x, uint32_t y, const font* f, double val);

  // draw text with a fixed pixel limit. Return the number of characters drawn
  uint32_t text(uint32_t x, uint32_t y, const font* f, const char text[], uint32_t len, uint32_t max_width);

  // draw text centered within a box of size width
  void centered_text(uint32_t x, uint32_t y, uint32_t width,
            const font* f, const char text[], uint32_t len);

  // draw text centered within a rectangle whose top-left corner is x,y
  // and that is width x height
  void xycentered_text(uint32_t x, uint32_t y, uint32_t width, uint32_t height,
            const font* f, const char text[], uint32_t len);

  // right justified
  void right_text(uint32_t x, uint32_t y, uint32_t width,
            const font* f, const char text[], uint32_t len);

};

/**
 * Represent the visual form of a letter in a particular font
 * including the dimensions of all 
 * see: glyph.jpg
 */
class glyph {
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

#if 0
/**
 * Future improvment, write a font block loader that loads itself from disk in a single fast read
 * This is not as compact as it could be, fonts are 64-bit aligned for optimized read times
 * not for loading from disk which only happens once.
 * This means that as much as 63 bits can be wasted if the size of the character bitmap
 * is not an even multiple of 64.
 */
class fast_font : public BlockLoader {
private:
  const glyph* glyphs;
  uint32_t height; // vertical height of this font
  uint64_t* bitmap; // pointer to the internal memory
public:
  // read in a font file and create the font in a single continguous block of memory
  fast_font(const char filename[]);
};
#endif

class font_face {
private:
  std::vector<font> fonts;
public:
  font_face(const char filename[]);
  const font* get(const char faceName[], uint32_t size);
};

int main() {
  const font_face fonts("font.conf"); // load up different fonts(face, size)
  const font* default = fonts.get("Helvetica", 20);
  const font* big = fonts.get("Helvetica", 28);
  const font* small = fonts.get("Helvetica", 12);
  bitmap bm(1024,1024);
  bound_box b = bm.bounds().inset(10);
  bm.rect(10,10,bm.width() - 20, bm.height() - 20, color::WHITE);
  float x = 11, y = 30; // start of text

}
