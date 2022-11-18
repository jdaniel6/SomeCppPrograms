#include "color.hh"

// was in Little Endian; converted to Big Endian

color color::RED = {0xFF0000FF};
color color::GREEN = {0xFF00FF00};
color color::BLUE = {0xFFFF0000};
color color::WHITE = {0xFFFFFFFF};
color color::BLACK = {0x00000000};
color color::YELLOW = {0xFF00FFFF};
color color::PINK = {0xFFFF00FF};

uint32_t color::getrgba(){
    return this->val;
}