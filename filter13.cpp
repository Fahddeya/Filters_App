#include <iostream>
#include "Image_Class.h"
using namespace std;

Image sunlight(Image& image){
     
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            
            image(i, j, 0) = min(255, image(i, j, 0) + 40); // Increase red channel
            image(i, j, 1) = min(255, image(i, j, 1) + 30); // Increase green channel
            image(i, j, 2) = max(0, image(i, j, 2) - 10); // Decrease blue channel
        }
    }
    return image;
}

int main (){
    string name;
    Image image;
    cin >> name;
    image.loadNewImage(name);

    sunlight(image).saveImage("test.jpg");
}