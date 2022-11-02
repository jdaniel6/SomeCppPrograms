#ifndef COLOR__HH__
#define COLOR__HH__

#include <ostream>

class color {
private:
  uint32_t val;
public:
  color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {}
  color(uint32_t rgba) : val(rgba) {}
  color darker() const ; 
  color lighter() const ;
  uint32_t getrgba() ;
	static color RED, GREEN, BLUE, WHITE, BLACK, YELLOW, PINK;
  friend std::ostream& operator <<(std::ostream& s, const color c) ;
};

#endif
