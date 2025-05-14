#include <iostream>
#include "Image_Class.h"
using namespace std;


Image flipimage(Image image){
    for (int i = 0; i < image.width / 2; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                swap(image(i, j, k), image(image.width - 1 - i, j, k));
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
    flipimage(image).saveImage("test.jpg");
}