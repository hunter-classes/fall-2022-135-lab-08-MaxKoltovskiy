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

void halfInvert(std::string input)
{
    int h,w;
    int img[MAX_H][MAX_W];
    readImage(input, img, h, w);

    int out [MAX_H][MAX_W];

    int half = (w/2);

    for(int row = 0; row < h; row++) {
        for(int col = 0; col < half; col++) {
            out[row][col] = img[row][col];
        }
        for(int col = half; col < w; col++) {
            out[row][col] = 255- img[row][col];
        } 
    }

    writeImage("taskB.pgm", out, h, w);
}

void box(std::string input) 
{
    int h,w;
    int img[MAX_H][MAX_W];
    readImage(input, img, h, w);

    int out [MAX_H][MAX_W];

    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            out[row][col] = img[row][col];
        }
    }

    int ht = h/2, wt = w/2;

    for(int row = ht/2; row < h-(ht/2); row++) {
        for(int col = wt/2; col < w-(wt/2); col++) {
            out[row][col] = 255;
        }
    }

    writeImage("taskC.pgm", out, h, w);
}