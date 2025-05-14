#include <iostream>
#include <cmath>
#include "Image_Class.h"
using namespace std;



void filter_lightening7(string file_extinsion)
{
    Image image(file_extinsion);

    float light_value = 1.0 / 1.5;

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = pow(image(i, j, k) / 255.0, light_value) * 255;
            }
        }
    }

    

    image.saveImage("test.jpg");
}



int main(){

   string file_extension; 
   cin >> file_extension;
   filter_lightening7(file_extension); 
}