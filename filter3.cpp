#include <iostream>
#include "Image_Class.h"
using namespace std;


Image invertimage(Image image){
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                // Subtract each pixel value from maximum pixel value
                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }

    return image;
}


int main (){
    string name;
    Image image;
    cin >> name;
    image.loadNewImage(name);
    invertimage(image).saveImage("test.jpg");
}