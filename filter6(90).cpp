#include <iostream>
#include <string>
#include "Image_Class.h"

using namespace std;

void rotateImage90_6(string file_extension) {
    Image image1(file_extension);

    int newWidth = image1.height;
    int newHeight = image1.width;

    Image image2(newWidth, newHeight);

    for (int i = 0; i < image1.width; ++i) {
        for (int j = 0; j < image1.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image2(image1.height - 1 - j, i, k) = image1(i, j, k);
            }
        }
    }
    
    image2.saveImage("test.jpg"); 
}

int main() {
    string file_extension;
    cout << "Please enter the image name to rotate 90 degrees clockwise: ";
    cin >> file_extension;
    rotateImage90_6(file_extension);

}
