#include <iostream>
#include "imageio.h"
#include "funcs.h"

void invert(std::string input) 
{
    int h,w;
    int img[MAX_H][MAX_W];
    readImage(input, img, h, w);

    int out[MAX_H][MAX_W];

    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            out[row][col] = (255 - img[row][col]);
        }
    }

    writeImage("taskA.pgm", out, h, w);
  
}