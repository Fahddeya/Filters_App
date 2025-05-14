#include <iostream>
#include "Image_Class.h"

using namespace std;

void merge_two_images(string filename1,string filename2,int width1,int height1){
    Image first_image(filename1);
    Image second_image(filename2);
    Image third_image(width1,height1);
    Image fourth_image(width1,height1);
    float X = (float)first_image.width / third_image.width;
    float Y = (float)first_image.height / third_image.height;
    for (int i = 0; i < third_image.width; ++i) {
        for (int j = 0; j < third_image.height; ++j) {
            for( int  k = 0 ; k < 3 ; ++k ){
            int srcX = (int)(i * X);
            int srcY = (int)(j * Y);

           
            third_image(i, j, k) = first_image(srcX, srcY,k);
            }
        }
    }
    float X2 = (float)second_image.width / fourth_image.width;
    float Y2= (float)second_image.height / fourth_image.height;
    for (int i = 0; i < fourth_image.width; ++i) {
        for (int j = 0; j < fourth_image.height; ++j) {
            for( int  k = 0 ; k < 3 ; ++k ){
            int srcX = (int)(i * X2);
            int srcY = (int)(j * Y2);

           
            fourth_image(i, j, k) = second_image(srcX, srcY,k);
            }
        }
    }

    Image mergedImage(width1, height1);

    for (int i = 0; i < mergedImage.width; ++i) {
        for (int j = 0; j < mergedImage.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int pixel1, pixel2;

             if (i < third_image.width && j < third_image.height) {
              pixel1 = third_image(i, j, k);
         } else {
               pixel1 = 0;
  }

          if (i < fourth_image.width && j < fourth_image.height) {
                  pixel2 = fourth_image(i, j, k);
          } else {
                 pixel2 = 0;
}


                mergedImage(i, j, k) = (pixel1 + pixel2)/2;
            }
        }
    }

    string mergedFilename;
    cout << "Please enter the image name to store the merged image and choose your extension\n";
    cin.ignore();
    getline(cin,mergedFilename);
    mergedImage.saveImage(mergedFilename);
    system(mergedFilename.c_str());
}


int main() {
    string image_name1,image_name2;
    int width, height;
    getline(cin,image_name1);
    getline(cin,image_name2);
    cout << "width: ";
    cin >> width;
    cout << "height: ";
    cin >> height;
    merge_two_images(image_name1,image_name2,width,height);
    return 0;
}
