#include <iostream>
#include <string>
#include <cmath>
#include "Image_Class.h"
using namespace std;
void detectBoundaries10(string file_extension) {

    Image image(file_extension);
    Image edges(image.width, image.height);

    for (int i = 1; i < image.width -1; ++i) {
        for (int j = 1; j < image.height -1; ++j) {
            for (int k = 0; k < 3; ++k) {
                int x = image.getPixel(i + 1, j, k) - image.getPixel(i - 1, j, k);
                int y = image.getPixel(i, j + 1, k) - image.getPixel(i, j - 1, k);
                int first=x*x;
                int second=y*y;
                int gradient = sqrt(first + second);

                edges.setPixel(i, j, k, 255 - gradient);
            }
        }
    }

    

    edges.saveImage("test.jpg");
}


int main() {
    string file_extension;
    cin >> file_extension;
    detectBoundaries10(file_extension);
}
