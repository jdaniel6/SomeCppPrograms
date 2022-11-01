#ifndef BOUND_BOX_HH_
#define BOUND_BOX_HH_

#include <cstdint>
#include <iostream>

class bound_box {
public:
    uint32_t x, y, w, h;
    bound_box(uint32_t x, uint32_t  y, uint32_t  w, uint32_t h);
    bound_box inset(uint32_t in) const;
};

#endif
