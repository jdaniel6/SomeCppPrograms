#include "glyph.hh"
//#include "bitmap.hh"
//#include "font_face.hh"
#include <fstream>
#include <iostream>
#include <cstdint>
#include <string>

glyph::glyph(uint32_t width, uint32_t height, 
        uint32_t advance, 
        uint32_t bearingX, uint32_t bearingY,
        uint32_t offset) : width(width), height(height), advance(advance), bearingX(bearingX), bearingY(bearingY), offset(offset) {
        #if 0
                uint32_t width = eval_width(image_file);
                uint32_t height = eval_height(image_file);
                uint32_t advance = eval_advance(image_file);
                uint32_t bearingX = eval_bearingX(image_file);
                uint32_t bearingY = eval_bearingY(image_file);
                uint32_t offset = eval_offset(image_file);
        #endif
        }

#if 0
/* 
        All eval_ functions should look at an image and take the point
        TODO: add ways to locate these points from an image
        TODO: open input image_file 
*/
uint32_t eval_bearingX(image_file) { // Locate the left-most point in the glyph
        return uint32_t x = 0;   // Set the basic point to be 0
}

uint32_t eval_bearingY(image_file) { // Locate the top-most point in the glyph
        return uint32_t y = 0;  // Set value to 0
}

uint32_t eval_width(image_file) {  
        uint32_t x_Max = 0, x_Min = 0; // x_Min should be equal to bearingX
        return x_Max - x_Min; //width is the difference between right-most and left-most points
}

uint32_t eval_height(image_file) {
        uint32_t y_Max = 0, y_Min = 0; // y_Max should be equal to bearingY
        return y_Max - y_Min; // height is the difference between top-most and bottom-most points
}

uint32_t eval_advance(image_file) {
        uint32_t x_initial = 0, x_final = 0; // x_initial = origin; x_final = x_Max + bearingX
        return x_final - x_initial;
}

uint32_t eval_offset(image_file) {}

/*
        Get returns glyph from font
*/

uint32_t glyph::get(const glyph& a, std::string str) { //string is font name
        if (str == "width") {
                return a.width;
        }
        else if (str == "height") {
                return a.height;
        }
        else if (str == "bearingX") {
                return a.bearingX;
        }
        else if (str == "bearingY") {
                return a.bearingY;
        }
        else if (str == "advance") {
                return a.advance;
        }
        else if (str == "offset") {
                return a.offset;
        }
}

/*
        Output values to bitmap
*/

void glyph::render(bitmap& bm, uint32_t x, uint32_t y) {
        
}
#endif