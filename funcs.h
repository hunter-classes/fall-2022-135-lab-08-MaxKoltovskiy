#include <string>     
#include "imageio.h"
void invert(std::string);
void halfInvert(std::string);
void box(std::string);
void frame(std::string);
void scale(std::string);
void twoByTwo(int (&out)[MAX_H][MAX_W], int, int, int);
void pixelate(std::string);