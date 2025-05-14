#include <iostream>
#include "Image_Class.h"
using namespace std;


Image flipimagev(Image image){
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height / 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                swap(image(i, j, k), image(i, image.height - 1 - j, k));
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
    flipimagev(image).saveImage("test.jpg");
}