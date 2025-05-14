#include <iostream>
#include "Image_Class.h"
using namespace std;


void infrared(string file_extension){

Image image1 (file_extension);

    for (int i = 0; i < image1.width; i++) {
        for (int j = 0; j < image1.height; j++) {
            
            image1(i, j, 0) = 255;
            image1(i, j, 1) = 255 - image1(i,j,1);
            image1(i, j, 2) = 255 - image1(i,j,2);
        }
    }
    
    image1.saveImage("test.jpg");
}



int main(){
    string file_extension;
    cin >> file_extension;
    infrared(file_extension);
}