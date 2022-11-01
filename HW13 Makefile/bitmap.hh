#ifndef BITMAP_HH_
#define BITMAP_HH_

/**
 * Represent a bitmap where each pixel is a 32-bit number containing
 * RGBA (red, green, blue, alpha) 8-bits each
 * TODO: define, probably little-endian
 */
#include <cstdint>
#include "color.hh"
#include "font.hh"

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
  uint32_t& operator ()(uint32_t x, uint32_t y);
  // readonly lookup a single pixel
  //uint32_t operator ()(uint32_t x, uint32_t y);

  // draw horizontal line from (x1,y) to (x2,y)
  // note this can be significantly faster than arbitrary diagonals
  void horiz_line(uint32_t x1, uint32_t x2, uint32_t y, color c);

  // draw vertical line from (x,y1) to (x,y2)
  // note this can be significantly faster than arbitrary diagonals
  void vert_line(uint32_t x, uint32_t y1, uint32_t y2, color c);

  // draw an arbitrary diagonal line from (x1,y1) to (x2,y2) in color c
  // see Bresenham algorithm in wikipedia
  void line(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, color c);

  void rect(uint32_t x1, uint32_t y1, uint32_t w, uint32_t h, color c);
  void fill_rect(uint32_t x1, uint32_t y1, uint32_t w, uint32_t h, color c);

  void circle(uint32_t xc, uint32_t yc, uint32_t r, color c);
  void fill_circle(uint32_t xc, uint32_t yc, uint32_t r, color c);

  void ellipse(uint32_t xc, uint32_t yc, uint32_t r, color c);
  void fill_ellipse(uint32_t xc, uint32_t yc, uint32_t rx, uint32_t ry, color c);
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
  void text(uint32_t x, uint32_t y, const font* f, const char text[]);
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

  // save the bitmap to a file        
  void save(std::string filename);

};

#endif