#include <iostream>
#include "Image_Class.h"

using namespace std;

void resize11_ratio(string image1,string new_name,int ratio){
    Image image(image1);
    int width,height;
    width = image.width*ratio/100;
    height = image.height*ratio/100;
    Image resized_image(width, height);

    float X = (float)image.width / resized_image.width;
    float Y = (float)image.height / resized_image.height;
    for (int i = 0; i < resized_image.width; ++i) {
        for (int j = 0; j < resized_image.height; ++j) {
            for( int  k = 0 ; k < 3 ; ++k ){
            int srcX = (int)(i * X);
            int srcY = (int)(j * Y);

           
            resized_image(i, j, k) = image(srcX, srcY,k);
            }
        }
    }

    resized_image.saveImage(new_name);
}





int main()
{
    string image1, new_name;
    int ratio;

    cin >> image1>>ratio>>new_name;

    resize11_ratio(image1,new_name,ratio);
}