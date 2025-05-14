#include <iostream>
#include <string>
#include "Image_Class.h"

using namespace std;

void blur12(string file_extension) {
    Image image1(file_extension);
    Image blurred_image = image1;

    for (int x = 0; x < image1.width; ++x) {
        for (int y = 0; y < image1.height; ++y) {

            int red = 0, green = 0, blue = 0, count = 0;

            for (int i = -10; i <= 10; ++i) {
                for (int j = -10; j <= 10; ++j) {
                    int p = x + i;
                    int q = y + j;

                    if (p >= 0 && p < image1.width && q >= 0 && q < image1.height) {
                        red += image1(p, q, 0);
                        green += image1(p, q, 1);
                        blue += image1(p, q, 2);
                        count++;
                    }
                }
            }

            int avg_red = red / count;
            int avg_green =green / count;
            int avg_blue = blue / count;

            blurred_image(x, y, 0) = avg_red;
            blurred_image(x, y, 1) = avg_green;
            blurred_image(x, y, 2) = avg_blue;
        }
    }
    
    blurred_image.saveImage("test.jpg"); 
}

int main() {
    string file_extension;
    cout << "Please enter the image name to rotate 90 degrees clockwise: ";
    cin >> file_extension;
    blur12(file_extension);

}
