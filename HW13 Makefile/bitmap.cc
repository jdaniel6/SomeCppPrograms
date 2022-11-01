#include<iostream>
#include<fstream>
#include<string>
#include<cstdint>

#include "bitmap.hh"
#include "bound_box"
#include "color.hh"
#include "font_face.hh"
#include "font.hh"
#include "glyph.hh"

/*
#include<>
#include<>
*/

bitmap::bitmap(uint32_t w, uint32_t h)
 : w(w), h(h), pixels(new uint32_t[w*h]){
//TODO: let's check out the random noise....
 }

bitmap::~bitmap(){
     delete [] pixels;  
}
/*
// we won't support copying bitmaps yet
bitmap(const bitmap& orig) = delete;
bitmap& operator =(const bitmap& orig) = delete;
*/
// read/write a single pixel
uint32_t& bitmap::operator ()(uint32_t x, uint32_t y) {
     return pixels[y * w + x];
}
// readonly lookup a single pixel
uint32_t bitmap::operator ()(uint32_t x, uint32_t y) const {
     return pixels[y * w + x];
}

// draw horizontal line from (x1,y) to (x2,y)
// note this can be significantly faster than arbitrary diagonals
void bitmap::horiz_line(uint32_t x1, uint32_t x2, uint32_t y, color c){
  uint32_t start = x1 + y * w;
  uint32_t end = x2 + y * w;
  //TODO: now fill in the dots...
}

// draw vertical line from (x,y1) to (x,y2)
// note this can be significantly faster than arbitrary diagonals
void bitmap::vert_line(uint32_t x, uint32_t y1, uint32_t y2, color c){

}

// draw an arbitrary diagonal line from (x1,y1) to (x2,y2) in color c
// see Bresenham algorithm in wikipedia
void bitmap::line(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, color c){

}

void bitmap::rect(uint32_t x1, uint32_t y1, uint32_t w, uint32_t h, color c)){

}
void bitmap::fill_rect(uint32_t x1, uint32_t y1, uint32_t w, uint32_t h, color c)){

}

void bitmap::circle(uint32_t xc, uint32_t yc, uint32_t r, color c)){

}
void bitmap::fill_circle(uint32_t xc, uint32_t yc, uint32_t r, color c)){

}

void bitmap::ellipse(uint32_t xc, uint32_t yc, uint32_t r, color c)){

}
void bitmap::fill_ellipse(uint32_t xc, uint32_t yc, uint32_t rx, uint32_t ry, color c)){

}
void bitmap::grid(uint32_t x, uint32_t y, uint32_t dx, uint32_t dy, uint32_t num_rows,  uint32_t num_cols){
     
}
void bitmap::gouraud(uint32_t x1, uint32_t y1, color c1, uint32_t x2, uint32_t y2, color c2, uint32_t x3, uint32_t y3, color c3){

}
void bitmap::triangle(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3, color c){

}
void bitmap::quad(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3, uint32_t x4, uint32_t y4, color c){

}
void bitmap::fill_quad(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3, uint32_t x4, uint32_t y4, color c){

}
void bitmap::fill_quad(uint32_t x1, uint32_t y1, color c1, uint32_t x2, uint32_t y2, color c2, uint32_t x3, uint32_t y3, color c3, uint32_t x4, uint32_t y4, color c4){

}
void bitmap::fill_grid(uint32_t x[], uint32_t xlen, uint32_t y[], uint32_t ylen,  float data[]){

}
// draw a cubic bezier curve
//TODO: specify the resolution of the line segments?
void bitmap::bezier(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3, color c){

}
// draw a sequence of connected cubic beziers where
// the first point of each is the last of the previous
void bitmap::bezier(float pts[], uint32_t len, color c){

}

// piecewise cubic hermite interpolation
// see: https://www.mathworks.com/help/matlab/ref/pchip.html
void bitmap::pchip(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3, color c){

}
void bitmap::lagrange(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3, color c){

}


void bitmap::natural_spline(float pts[], uint32_t len, color c){

}

void bitmap::text(uint32_t x, uint32_t y, const font* f, const char text[], uint32_t len){

}

// inline convenience function for nul-terminated strings
void bitmap::text(uint32_t x, uint32_t y, const font* f, const char text[]) {//text(x, y, f, text, strlen(text))

}
void bitmap::text(uint32_t x, uint32_t y, const font* f, uint32_t val){

}
void bitmap::text(uint32_t x, uint32_t y, const font* f, uint64_t val){

}
void bitmap::text(uint32_t x, uint32_t y, const font* f, double val){

}

// draw text with a fixed pixel limit. Return the number of characters drawn
uint32_t bitmap::text(uint32_t x, uint32_t y, const font* f, const char text[], uint32_t len, uint32_t max_width){

}

// draw text centered within a box of size width
void bitmap::centered_text(uint32_t x, uint32_t y, uint32_t width, const font* f, const char text[], uint32_t len){

}

// draw text centered within a rectangle whose top-left corner is x,y
// and that is width x height
void bitmap::xycentered_text(uint32_t x, uint32_t y, uint32_t width, uint32_t height, const font* f, const char text[], uint32_t len){

}

// right justified
void bitmap::right_text(uint32_t x, uint32_t y, uint32_t width, const font* f, const char text[], uint32_t len){

}