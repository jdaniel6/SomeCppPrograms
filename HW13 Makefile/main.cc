/**
 * @file main.cc
 * @author Jeffrey Daniel (jdaniel6@stevens.edu)
 * @brief A program to work with bitmap objects and use Makefile
 * @version 0.1
 * @date 2022-11-01
 * @ref https://stackoverflow.com/a/34427391 for linking and using makefile
 * @ref https://developers.google.com/speed/webp/docs/api for working with WebP library
 * @ref https://stackoverflow.com/questions/72079311/c-load-webp-file-into-array for help in writing the bitmap save function
 * @ref https://www.digital-detective.net/understanding-big-and-little-endian-byte-order/ for debugging color.cc
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "font_face.hh"
#include "bound_box.hh"
#include "color.hh"
#include "bitmap.hh"


// we are not implementing this yet, but at least it should compile!
// note: this function is not called, so it does not have to work!
void test_text() {
  const font_face fonts("font.conf"); // load up different fonts(face, size)
  const font* def = fonts.get("Helvetica", 20);
  const font* big = fonts.get("Helvetica", 28);
  const font* small = fonts.get("Helvetica", 12);
  bitmap bm(512, 512);
  //bound_box b = bm.bounds().inset(10);
  //bm.rect(10,10,bm.width() - 20, bm.height() - 20, color::WHITE);
  float x = 11, y = 30; // start of text
}

void test_basic_drawing() {
  bitmap bm(512, 512);
  bm.horiz_line(10, 200, 100, color::RED);
  bm.vert_line(30, 300, 100, color::BLUE);
  bm.rect(100,150, 50,25, color::GREEN);
  bm.fill_rect(100,250,50,25, color::YELLOW);
  bm.save("draw.webp"); //see https://developers.google.com/speed/webp/docs/api
}

int main() {
  test_basic_drawing();
}
