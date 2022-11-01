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

    int out[MAX_H][MAX_W];

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

void frame(std::string input)
{
    int h,w;
    int img[MAX_H][MAX_W];
    readImage(input, img, h ,w);

    int out[MAX_H][MAX_W];

    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            out[row][col] = img[row][col];
        }
    }

    int h_quarter = h/4, w_quarter = w/4;

    for(int row = h_quarter; row <= h-(h_quarter); row++) {
        for(int col = w_quarter; col <= w-(w_quarter); col++) {
            if(col == w_quarter || row == h_quarter) {
                out[row][col] = 255;
            }
            if(col == w-(w_quarter) || row == h-(h_quarter)) {
                out[row][col] = 255;
            }
        }
    }

    writeImage("taskD.pgm", out, h, w);
}

void scale(std::string input)
{
    int h,w;
    int img[MAX_H][MAX_W];
    readImage(input, img, h, w);

    int out[MAX_H][MAX_W];

    int out_row = 0, out_col = 0;
    for(int row = 0; row < h; row++) {
        for(int col = 0; col< w; col++) {
            int pixel = img[row][col];
            out[out_row][out_col] = pixel;
            out[out_row][out_col+1] = pixel;
            out[out_row+1][out_col] = pixel;
            out[out_row+1][out_col+1] = pixel;
            out_col+=2;
        }
        out_row+=2;
        out_col = 0;
    }

    writeImage("taskE.pgm", out, h*2, w*2);
}
