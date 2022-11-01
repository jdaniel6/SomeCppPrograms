#include "bound_box.hh"

using namespace  std;

bound_box::bound_box(uint32_t x, uint32_t  y, uint32_t  w, uint32_t h) 
  : x(x), y(y), w(w), h(h) {}

bound_box bound_box::inset(uint32_t in) const {
    return bound_box(x + in, y + in, w - 2*in, h - 2*in);
}
