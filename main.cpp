#include "funcs.h"
#include <iostream>

int main() 
{
    invert("image1.pgm");
    std::cout<< "Image with inverted colors = \"taskA.pgm\" \n";

    halfInvert("image2.pgm"); 
    std::cout<< "Image with only right half inverted colors = \"taskB.pgm\" \n";

    box("image1.pgm");
    std::cout<< "Image with white box in the middle = \"taskC.pgm\" \n";

    frame("image2.pgm");
    std::cout<< "Framed Image = \"taskD.pgm\" \n";

    scale("image3.pgm");
    std::cout<< "Scaled Image = \"taskE.pgm\" \n";

    pixelate("image3.pgm");
    std::cout<< "Pixelated Image = \"taskF.pgm\" \n";

}