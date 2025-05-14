#include <iostream>
#include "Image_Class.h"
using namespace std;


void f9simple(string file_extension, int thickness, const unsigned char framecolor[3]) {

    Image image(file_extension);
    int frame_width = image.width + 2 * thickness;
    int frame_height = image.height + 2 * thickness;
    Image image2(frame_width, frame_height);

    for (int i = 0; i < frame_width; ++i) {
        for (int j = 0; j < frame_height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                image2(i, j, k) = framecolor[k];
            }
        }
    }

    for (int i = thickness; i < image.width + thickness; ++i) {
        for (int j = thickness; j < image.height + thickness; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                image2(i, j, k) = image(i - thickness, j - thickness, k);
            }
        }
    }
    image2.saveImage("test.jpg");
}

void frame_color(unsigned char frameColor1[3], int choice3) {
    switch (choice3) {
        case 1:
            frameColor1[0] = 0;
            frameColor1[1] = 0;
            frameColor1[2] = 255; //blue
            break;
        case 2:
            frameColor1[0] = 255;
            frameColor1[1] = 0;
            frameColor1[2] = 0; //red
            break;
        case 3:
            frameColor1[0] = 255;
            frameColor1[1] = 255;
            frameColor1[2] = 0; //yellow
            break;
        case 4:
            frameColor1[0] = 11;
            frameColor1[1] = 171;
            frameColor1[2] = 0; //green
            break;
        case 5:
            frameColor1[0] = 155;
            frameColor1[1] = 1;
            frameColor1[2] = 186; //purple
            break;
        case 6:
            frameColor1[0] = 253;
            frameColor1[1] = 138;
            frameColor1[2] = 238; //pink
            break;
        case 7:
            frameColor1[0] = 249;
            frameColor1[1] = 141;
            frameColor1[2] = 58; //orange
        default:
            cout << "Invalid choice. set to white color." << endl;
            frameColor1[0] = frameColor1[1] = frameColor1[2] = 255;// white
    }
}




int main (){
    string file_extension;
    Image image;
    cin >> file_extension;
    
    int choice3;
    int thickness = 0;
    unsigned char framecolor[3];
    cout << "Enter the thickness of the frame: ";
    cin >> thickness;

    cout << "Enter the color of the frame you want:" << endl;
    cout << "1. Blue" << endl;
    cout << "2. Red" << endl;
    cout << "3. Yellow" << endl;
    cout << "4. Green" << endl;
    cout << "5. Purple" << endl;
    cout << "6. Pink" << endl;
    cout << "7. Orange" << endl;
    cout << "Enter your choice: ";
    cin >> choice3;

    frame_color(framecolor, choice3);
    f9simple(file_extension, thickness, framecolor);
}