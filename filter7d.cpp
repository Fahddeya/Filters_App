#include <iostream>
#include <cmath>
#include "Image_Class.h"
using namespace std;



void filter_darkening7(string file_extinsion)
{
    Image image(file_extinsion);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) /= 2; //divide the image pixels by 2 for darkening
            }
        }
    }

    

    image.saveImage("test.jpg");
}



int main(){

   string file_extension; 
   cin >> file_extension;
   filter_darkening7(file_extension); 
}