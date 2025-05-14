#include <iostream>
#include "Image_Class.h"
using namespace std;

void purple16(string file_extension) {
  Image image(file_extension);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            
            image(i, j, 0) = min(255, image(i, j, 0) + 60); // red channel
            image(i, j, 1) = max(0, image(i, j, 1) - 0); //  green channel
            image(i, j, 2) = min(255, image(i, j, 2) + 40); // blue channel
        }
    }

    image.saveImage("test.jpg");
}


int main (){
    string file_extension;
    cin >> file_extension;
    purple16(file_extension);
}