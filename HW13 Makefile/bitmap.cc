/**
 * @file bitmap.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A program to work with bitmap objects and use Makefile
 * @version 0.1
 * @date 2022-11-09
 * @ref https://stackoverflow.com/a/34427391 for linking and using makefile
 * @ref https://developers.google.com/speed/webp/docs/api for working with WebP library
 * @ref https://stackoverflow.com/questions/72079311/c-load-webp-file-into-array for help in writing the bitmap save function
 * @ref https://www.digital-detective.net/understanding-big-and-little-endian-byte-order/ for debugging color.cc
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>

#include "bitmap.hh"
#include "bound_box.hh"
#include "color.hh"
#include "font_face.hh"
#include "font.hh"
#include "glyph.hh"
#include "encode.h"

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
//uint32_t bitmap::operator ()(uint32_t x, uint32_t y) const {
     //return pixels[y * w + x];
//}

// draw horizontal line from (x1,y) to (x2,y)
// note this can be significantly faster than arbitrary diagonals
void bitmap::horiz_line(uint32_t x1, uint32_t x2, uint32_t y, color c){
     if(x1 > x2){
          uint32_t temp = x2;
          x2 = x1;
          x1 = temp;
     }
     uint32_t start = x1 + y * w;
     uint32_t end = x2 + y * w;
     //TODO: now fill in the dots...
     for(uint32_t pos = start; pos <= end; pos++){
          pixels[pos] = c.getrgba();
     }
}

// draw vertical line from (x,y1) to (x,y2)
// note this can be significantly faster than arbitrary diagonals
void bitmap::vert_line(uint32_t x, uint32_t y1, uint32_t y2, color c){
     if(y1 > y2){
          uint32_t temp = y2;
          y2 = y1;
          y1 = temp;
     }
     uint32_t start = x + y1 * w;
     uint32_t end = x + y2 *w ;
     for(uint32_t pos = start; pos <=end; pos+=w){
          pixels[pos] = c.getrgba();
     }
}

// draw an arbitrary diagonal line from (x1,y1) to (x2,y2) in color c
// see Bresenham algorithm in wikipedia
void bitmap::line(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, color c){

}

void bitmap::rect(uint32_t x1, uint32_t y1, uint32_t w, uint32_t h, color c){
     horiz_line(x1, x1 + w, y1, c);
     vert_line(x1 + w, y1, y1 + h, c);
     horiz_line(x1, x1 + w, y1 + h, c);
     vert_line(x1, y1, y1 + h, c);

}
void bitmap::fill_rect(uint32_t x1, uint32_t y1, uint32_t wid, uint32_t hei, color c){
     uint32_t y_end = ((y1 + hei) > h) ? h : (y1 + hei);
     uint32_t x_end = ((x1 + wid) > w) ? w : (x1 + wid);
     for(uint32_t y_pos = y1; y_pos <= y_end; y_pos++){
          for(uint32_t x_pos = x1; x_pos <= x_end; x_pos++){
               pixels[x_pos + y_pos * w] = c.getrgba();
          }
          std::cout << "\n";
     }
}

void bitmap::circle(uint32_t xc, uint32_t yc, uint32_t r, color c){

}
void bitmap::fill_circle(uint32_t xc, uint32_t yc, uint32_t r, color c){

}

void bitmap::ellipse(uint32_t xc, uint32_t yc, uint32_t r, color c){

}
void bitmap::fill_ellipse(uint32_t xc, uint32_t yc, uint32_t rx, uint32_t ry, color c){

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
     return 0;
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
// save the bitmap to a file
void bitmap::save(std::string filename){
     uint8_t* output;
     size_t size = WebPEncodeLosslessRGBA((uint8_t*)pixels, w, h, 4 * w, &output);
     std::ofstream os(filename, std::ios::binary);
     os.write((char*)output, size);
     WebPFree(output);
}

