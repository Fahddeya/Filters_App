#include <iostream>
#include "Image_Class.h"

using namespace std;

int main() {
    string filename;
    cout << "Enter source image name to turn to gray scale: ";
    cin >> filename;

    Image image(filename);

    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned short int r = 0, g = 0, b = 0;
            r = image(i, j, 0);
            g = image(i, j, 1);
            b = image(i, j, 2);
            unsigned short int avg =static_cast<unsigned short int>((r + g + b) / 3);
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }

    cout << "Enter target name to store new image: ";
    cin >> filename;
    cout << "Add specific extensions .jpg .bmp .png .tga";
    image.saveImage(filename);
    return 0;
}
