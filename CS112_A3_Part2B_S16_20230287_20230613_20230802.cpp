// File name: CS112_A3_Part2B_S16_20230287_20230613_20230802.cpp

// Purpose: this program is an image editor which apply some filters to imaage you choose then ask the user
// if he want to save the edited image over the old one or to create a new file taking its name from the user
// and spacify the extension of the file from the user
// and repeat the process till the user type exit.

// Authers:
// first: Fahd Deya El-din Salah El-din Ahmed -- S16 -- Email: fahd.cu2004@gmail.com
// second: Mohamed Ashraf Mahmoud Ahmed -- S16 -- Email: mohamedashraf1304@gmail.com
// third: Nesrain Sadeq Mohammed -- S16 -- Email: nesreensadiq347@gmail.com

// first ID: 20230287 -- the 1st, 7th, 10th, and 17th filters and the menus
// second ID: 20230613 -- the 2nd, 4th, 8th, 11th and 13th filters
// third ID: 20230802 -- the 3rd, 5th, 6th, 9th, 12th, and 16th filters

// rebo link: https://github.com/Fahddeya/Assignment-3

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Image_Class.h"

using namespace std;

bool hasImageExtension(const string& file_extension) {    //// check the input if it a valid image file name with extension
    vector<string> imageExtensions = {".jpg", ".jpeg", ".png", ".gif", ".bmp"};  //// create vector with the valid extension

    size_t pos = file_extension.find_last_of('.');        //// find the postion of the last '.' iin the input
    if (pos == string::npos || pos == 0)                  //// if the point doesn't exist or in the first so it's an error 
        return false;

    string extension = file_extension.substr(pos);        //// create a string with the input after the '.' and name it extension
    transform(extension.begin(), extension.end(), extension.begin(), ::tolower);   //// turn each carachter in the extension into lower letter

    return find(imageExtensions.begin(), imageExtensions.end(), extension) != imageExtensions.end(); 
    //// return true if the string extension matches a string in the vectore ////
}   

void grayscale1(string file_extension){       //// 1st filter
    Image image(file_extension);

    for (int i = 0; i < image.width; i++){
        for (int j = 0; j < image.height; j++){
            unsigned short int r = 0, g = 0, b = 0;
            r = image(i, j, 0);
            g = image(i, j, 1);
            b = image(i, j, 2);
            unsigned short int avg = static_cast<unsigned short int>((r + g + b) / 3);
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }
    cout << "you want to save the new image or apply the filter in the same image?\n";
    cout << "1) same image.\n";
    cout << "2) new image.\n";       
    char choice2;
    cin >> choice2;
    
    while(choice2 != '1' && choice2 != '2'){         //// validation test
        cout << "invalid choice, please try again.\n";
        cin >> choice2;
    }
   
    if(choice2 =='1'){                  //// incase the user choose to save the image in the same file as old one
        cin.ignore();
        cout << "the image has been updated.\n";
        image.saveImage(file_extension);
        system(file_extension.c_str());
    }
    else if(choice2 =='2'){             //// incase the user choose to create a new file to the new image
        string newname;
        cout << "please enter the name of the new file 'hint: with the extension'\n";
        cin.ignore();
        getline(cin, newname);
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(newname)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, newname);
            }
        }
        image.saveImage(newname);
        cout << "new image created succesfully.\n";
        system(newname.c_str());
    }
}

void black_white2(string file_extension){     //// 2nd filter
    Image image(file_extension);

    for (int i = 0; i < image.width; i++){
        for (int j = 0; j < image.height; j++){
            unsigned short int r = 0, g = 0, b = 0;
            r = image(i, j, 0);
            g = image(i, j, 1);
            b = image(i, j, 2);
            unsigned short int avg = static_cast<unsigned short int>((r + g + b) / 3);
            if(avg > 128){
            image(i, j, 0) = 255;
            image(i, j, 1) = 255;
            image(i, j, 2) = 255;
            }
            else if(avg < 128){
            image(i, j, 0) = 0;
            image(i, j, 1) = 0;
            image(i, j, 2) = 0;
            }
        }
    }
    cout << "you want to save the new image or apply the filter in the same image?\n";
    cout << "1) same image.\n";
    cout << "2) new image.\n";
    char choice2;
    cin >> choice2;
    
    while(choice2 != '1' && choice2 != '2'){         //// validation test
        cout << "invalid choice, please try again.\n";
        cin >> choice2;
    }
   
    if(choice2 =='1'){                           //// incase the user choose to save the image in the same file as old one
        cin.ignore();
        cout << "the image has been updated.\n";
        image.saveImage(file_extension);
        system(file_extension.c_str());
    }
    else if(choice2 =='2'){                     //// incase the user choose to create a new file to the new image
        string newname;
        cout << "please enter the name of the new file 'hint: with the extension'\n";
        cin.ignore();
        getline(cin, newname);
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(newname)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, newname);
            }
        }
        image.saveImage(newname);
        cout << "new image created succesfully.\n";
        system(newname.c_str());
    }
}

void Invert3(string file_extension){          //// 3rd filter 
    Image image(file_extension);
    for (int i = 0; i < image.width; ++i){
        for (int j = 0; j < image.height; ++j){
            for (int k = 0; k < 3; ++k){
                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }
    cout << "you want to save the new image or apply the filter in the same image?\n";
    cout << "1) same image.\n";
    cout << "2) new image.\n";
    char choice2;
    cin >> choice2;
    
    while(choice2 != '1' && choice2 != '2'){         //// validation test
        cout << "invalid choice, please try again.\n";
        cin >> choice2;
    }
   
    if(choice2 =='1'){                          //// incase the user choose to save the image in the same file as old one
        cin.ignore();
        cout << "the image has been updated.\n";
        image.saveImage(file_extension);
        system(file_extension.c_str());
    }
    else if(choice2 =='2'){                      //// incase the user choose to create a new file to the new image
        string newname;
        cout << "please enter the name of the new file 'hint: with the extension'\n";
        cin.ignore();
        getline(cin, newname);
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(newname)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, newname);
            }
        }
        image.saveImage(newname);
        cout << "new image created succesfully.\n";
        system(newname.c_str());
    }
}

void merge_two_images4(string filename1,string filename2,int width1,int height1){
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
    bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(mergedFilename)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, mergedFilename);
            }
        }
    mergedImage.saveImage(mergedFilename);
    system(mergedFilename.c_str());
}

void fliph5(string file_extension){           //// 5th filter (horizontal flip)
    Image image(file_extension);
    
    for (int i = 0; i < image.width / 2; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                swap(image(i, j, k), image(image.width - 1 - i, j, k));
            }
        }
    }
    cout << "you want to save the new image or apply the filter in the same image?\n";
    cout << "1) same image.\n";
    cout << "2) new image.\n";
    char choice2;
    cin >> choice2;
    
    while(choice2 != '1' && choice2 != '2'){          //// validation test
        cout << "invalid choice, please try again.\n";
        cin >> choice2;
    }

    if(choice2 =='1'){                             //// incase the user choose to save the image in the same file as old one
        cin.ignore();
        cout << "the image has been updated.\n";
        image.saveImage(file_extension);
        system(file_extension.c_str());
    }
    else if(choice2 =='2'){                         //// incase the user choose to create a new file to the new image
        string newname;
        cout << "please enter the name of the new file 'hint: with the extension'\n";
        cin.ignore();
        getline(cin, newname);
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(newname)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, newname);
            }
        }
        image.saveImage(newname);
        cout << "new image created succesfully.\n";
        system(newname.c_str());
    }
}
void flipv5(string file_extension){           //// 5th filter (vertical flip)
    Image image(file_extension);
    
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height / 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                swap(image(i, j, k), image(i, image.height - 1 - j, k));
            }
        }
    }
    cout << "you want to save the new image or apply the filter in the same image?\n";
    cout << "1) same image.\n";
    cout << "2) new image.\n";
    char choice2;
    cin >> choice2;
    
    while(choice2 != '1' && choice2 != '2'){              //// validation test
        cout << "invalid choice, please try again.\n";
        cin >> choice2;
    }
   
    if(choice2 =='1'){                              //// incase the user choose to save the image in the same file as old one
        cin.ignore();
        cout << "the image has been updated.\n";
        image.saveImage(file_extension);
        system(file_extension.c_str());
    }
    else if(choice2 =='2'){                          //// incase the user choose to create a new file to the new image
        string newname;
        cout << "please enter the name of the new file 'hint: with the extension'\n";
        cin.ignore();
        getline(cin, newname);
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(newname)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, newname);
            }
        }
        image.saveImage(newname);
        cout << "new image created succesfully.\n";
        system(newname.c_str());
    }
}

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
    
    cout << "you want to save the new image or apply the filter in the same image?\n";
    cout << "1) same image.\n";
    cout << "2) new image.\n";
    char choice2;
    cin >> choice2;
    
    while(choice2 != '1' && choice2 != '2'){              //// validation test
        cout << "invalid choice, please try again.\n";
        cin >> choice2;
    }
   
    if(choice2 =='1'){                              //// incase the user choose to save the image in the same file as old one
        cin.ignore();
        cout << "the image has been updated.\n";
        image2.saveImage(file_extension);
        system(file_extension.c_str());
    }
    else if(choice2 =='2'){                          //// incase the user choose to create a new file to the new image
        string newname;
        cout << "please enter the name of the new file 'hint: with the extension'\n";
        cin.ignore();
        getline(cin, newname);
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(newname)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, newname);
            }
        }
        image2.saveImage(newname);
        cout << "new image created succesfully.\n";
        system(newname.c_str());
}
}
void rotateImage180_6(string file_extension) {
    Image image1(file_extension);

    int newheight = image1.height;
    int newwidth = image1.width;

    Image image2(newwidth, newheight);

    for (int i = 0; i < image1.width; ++i) {
        for (int j = 0; j < image1.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image2(image1.width - 1 - i, image1.height - 1 - j, k) = image1(i, j, k);
            }
        }
    }
    
    cout << "you want to save the new image or apply the filter in the same image?\n";
    cout << "1) same image.\n";
    cout << "2) new image.\n";
    char choice2;
    cin >> choice2;
    
    while(choice2 != '1' && choice2 != '2'){              //// validation test
        cout << "invalid choice, please try again.\n";
        cin >> choice2;
    }
   
    if(choice2 =='1'){                              //// incase the user choose to save the image in the same file as old one
        cin.ignore();
        cout << "the image has been updated.\n";
        image2.saveImage(file_extension);
        system(file_extension.c_str());
    }
    else if(choice2 =='2'){                          //// incase the user choose to create a new file to the new image
        string newname;
        cout << "please enter the name of the new file 'hint: with the extension'\n";
        cin.ignore();
        getline(cin, newname);
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(newname)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, newname);
            }
        }
        image2.saveImage(newname);
        cout << "new image created succesfully.\n";
        system(newname.c_str());
}
}
void rotateImage270_6(string file_extension) {
    Image image1(file_extension);

    int newWidth = image1.height;
    int newHeight = image1.width;

    Image image2(newWidth, newHeight);

    for (int i = 0; i < image1.width; ++i) {
        for (int j = 0; j < image1.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image2(j, image1.width - 1 - i, k) = image1(i, j, k);
            }
        }
    }
    
    cout << "you want to save the new image or apply the filter in the same image?\n";
    cout << "1) same image.\n";
    cout << "2) new image.\n";
    char choice2;
    cin >> choice2;
    
    while(choice2 != '1' && choice2 != '2'){              //// validation test
        cout << "invalid choice, please try again.\n";
        cin >> choice2;
    }
   
    if(choice2 =='1'){                              //// incase the user choose to save the image in the same file as old one
        cin.ignore();
        cout << "the image has been updated.\n";
        image2.saveImage(file_extension);
        system(file_extension.c_str());
    }
    else if(choice2 =='2'){                          //// incase the user choose to create a new file to the new image
        string newname;
        cout << "please enter the name of the new file 'hint: with the extension'\n";
        cin.ignore();
        getline(cin, newname);
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(newname)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, newname);
            }
        }
        image2.saveImage(newname);
        cout << "new image created succesfully.\n";
        system(newname.c_str());
}
}

void lightening7(string file_extension)
{
    Image image(file_extension);

    float light_value = 1.0 / 1.5;

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = pow(image(i, j, k) / 255.0, light_value) * 255;
            }
        }
    }

    cout << "you want to save the new image or apply the filter in the same image?\n";
    cout << "1) same image.\n";
    cout << "2) new image.\n";
    char choice2;
    cin >> choice2;
    
    while(choice2 != '1' && choice2 != '2'){              //// validation test
        cout << "invalid choice, please try again.\n";
        cin >> choice2;
    }
   
    if(choice2 =='1'){                              //// incase the user choose to save the image in the same file as old one
        cin.ignore();
        cout << "the image has been updated.\n";
        image.saveImage(file_extension);
        system(file_extension.c_str());
    }
    else if(choice2 =='2'){                          //// incase the user choose to create a new file to the new image
        string newname;
        cout << "please enter the name of the new file 'hint: with the extension'\n";
        cin.ignore();
        getline(cin, newname);
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(newname)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, newname);
            }
        }
        image.saveImage(newname);
        cout << "new image created succesfully.\n";
        system(newname.c_str());
    }
}
void darkening7(string file_extension)
{
    Image image(file_extension);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) /= 2; //divide the image pixels by 2 for darkening
            }
        }
    }

    cout << "you want to save the new image or apply the filter in the same image?\n";
    cout << "1) same image.\n";
    cout << "2) new image.\n";
    char choice2;
    cin >> choice2;
    
    while(choice2 != '1' && choice2 != '2'){              //// validation test
        cout << "invalid choice, please try again.\n";
        cin >> choice2;
    }
   
    if(choice2 =='1'){                              //// incase the user choose to save the image in the same file as old one
        cin.ignore();
        cout << "the image has been updated.\n";
        image.saveImage(file_extension);
        system(file_extension.c_str());
    }
    else if(choice2 =='2'){                          //// incase the user choose to create a new file to the new image
        string newname;
        cout << "please enter the name of the new file 'hint: with the extension'\n";
        cin.ignore();
        getline(cin, newname);
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(newname)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, newname);
            }
        }
        image.saveImage(newname);
        cout << "new image created succesfully.\n";
        system(newname.c_str());
    }
}

void crop8(string file_extension,int start_x, int start_y,int width,int height){

    Image image1(file_extension);
    Image image2(width,height);

    while(true){
      if((start_x >= 0 && start_x <= image1.width) && ( start_y >= 0 && start_y <= image1.height))
        break;
      else{
        cout << "the starting point is out of the range, please try again.\n";
        cin >> start_x >> start_y;
      }
    }
    
    for(int i = start_x ; i < start_x + width ; ++i){
        for(int j = start_y ; j < start_y + height ; ++j){
            for(int k = 0 ; k < 3 ; ++k){
                image2(i-start_x,j-start_y,k) = image1(i,j,k);
            }

        }
    }
    cout << "you want to save the new image or apply the filter in the same image?\n";
    cout << "1) same image.\n";
    cout << "2) new image.\n";
    char choice2;
    cin >> choice2;
    
    while(choice2 != '1' && choice2 != '2'){         //// validation test
        cout << "invalid choice, please try again.\n";
        cin >> choice2;
    }
   
    if(choice2 =='1'){                          //// incase the user choose to save the image in the same file as old one
        cin.ignore();
        cout << "the image has been updated.\n";
        image2.saveImage(file_extension);
        system(file_extension.c_str());
    }
    else if(choice2 =='2'){                      //// incase the user choose to create a new file to the new image
        string newname;
        cout << "please enter the name of the new file 'hint: with the extension'\n";
        cin.ignore();
        getline(cin, newname);
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(newname)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, newname);
            }
        }
        image2.saveImage(newname);
        cout << "new image created succesfully.\n";
        system(newname.c_str());
    }

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
void frame_simple9(string file_extension, int thickness, const unsigned char framecolor[3]) {

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
    
    cout << "you want to save the new image or apply the filter in the same image?\n";
    cout << "1) same image.\n";
    cout << "2) new image.\n";
    char choice2;
    cin >> choice2;
    
    while(choice2 != '1' && choice2 != '2'){              //// validation test
        cout << "invalid choice, please try again.\n";
        cin >> choice2;
    }
   
    if(choice2 =='1'){                              //// incase the user choose to save the image in the same file as old one
        cin.ignore();
        cout << "the image has been updated.\n";
        image2.saveImage(file_extension);
        system(file_extension.c_str());
    }
    else if(choice2 =='2'){                          //// incase the user choose to create a new file to the new image
        string newname;
        cout << "please enter the name of the new file 'hint: with the extension'\n";
        cin.ignore();
        getline(cin, newname);
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(newname)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, newname);
            }
        }
        image2.saveImage(newname);
        cout << "new image created succesfully.\n";
        system(newname.c_str());
    }
}
void frame_fancy9(string file_extension, int thickness, const unsigned char frameColor[3]) {
    Image image(file_extension);
    int frame_width = image.width + 2 * thickness;
    int frame_height = image.height + 2 * thickness;
    Image framed_image(frame_width, frame_height);
    for (int i = 0; i < frame_width; ++i) {
        for (int j = 0; j < frame_height; ++j) {
            double distance = sqrt(pow(i - frame_width / 2, 2) + pow(j - frame_height / 2, 2));
            double gradient = 1.0 - distance / (frame_width / 2);
            unsigned char gradientColor[3];
            for (int k = 0; k < 3; ++k) {
                gradientColor[k] = frameColor[k] * gradient;
            }
            if (i < thickness || i >= frame_width - thickness || j < thickness || j >= frame_height - thickness) {
                for (int k = 0; k < image.channels; ++k) {
                    framed_image(i, j, k) = gradientColor[k];
                }
            } else {
                framed_image(i, j, 0) = image(i - thickness, j - thickness, 0);
                framed_image(i, j, 1) = image(i - thickness, j - thickness, 1);
                framed_image(i, j, 2) = image(i - thickness, j - thickness, 2);
            }
        }
    }
    
    cout << "you want to save the new image or apply the filter in the same image?\n";
    cout << "1) same image.\n";
    cout << "2) new image.\n";
    char choice2;
    cin >> choice2;
    
    while(choice2 != '1' && choice2 != '2'){              //// validation test
        cout << "invalid choice, please try again.\n";
        cin >> choice2;
    }
   
    if(choice2 =='1'){                              //// incase the user choose to save the image in the same file as old one
        cin.ignore();
        cout << "the image has been updated.\n";
        framed_image.saveImage(file_extension);
        system(file_extension.c_str());
    }
    else if(choice2 =='2'){                          //// incase the user choose to create a new file to the new image
        string newname;
        cout << "please enter the name of the new file 'hint: with the extension'\n";
        cin.ignore();
        getline(cin, newname);
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(newname)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, newname);
            }
        }
        framed_image.saveImage(newname);
        cout << "new image created succesfully.\n";
        system(newname.c_str());
    }
}

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

    cout << "you want to save the new image or apply the filter in the same image?\n";
    cout << "1) same image.\n";
    cout << "2) new image.\n";
    char choice2;
    cin >> choice2;
    
    while(choice2 != '1' && choice2 != '2'){              //// validation test
        cout << "invalid choice, please try again.\n";
        cin >> choice2;
    }
   
    if(choice2 =='1'){                              //// incase the user choose to save the image in the same file as old one
        cin.ignore();
        cout << "the image has been updated.\n";
        edges.saveImage(file_extension);
        system(file_extension.c_str());
    }
    else if(choice2 =='2'){                          //// incase the user choose to create a new file to the new image
        string newname;
        cout << "please enter the name of the new file 'hint: with the extension'\n";
        cin.ignore();
        getline(cin, newname);
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(newname)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, newname);
            }
        }
        edges.saveImage(newname);
        cout << "new image created succesfully.\n";
        system(newname.c_str());
    }
}

void resize_dimension11(string file_extension, int width, int height){
    Image image(file_extension);
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
    cout << "you want to save the new image or apply the filter in the same image?\n";
    cout << "1) same image.\n";
    cout << "2) new image.\n";
    char choice2;
    cin >> choice2;
    
    while(choice2 != '1' && choice2 != '2'){              //// validation test
        cout << "invalid choice, please try again.\n";
        cin >> choice2;
    }
   
    if(choice2 =='1'){                              //// incase the user choose to save the image in the same file as old one
        cin.ignore();
        cout << "the image has been updated.\n";
        resized_image.saveImage(file_extension);
        system(file_extension.c_str());
    }
    else if(choice2 =='2'){                          //// incase the user choose to create a new file to the new image
        string newname;
        cout << "please enter the name of the new file 'hint: with the extension'\n";
        cin.ignore();
        getline(cin, newname);
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(newname)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, newname);
            }
        }
        resized_image.saveImage(newname);
        cout << "new image created succesfully.\n";
        system(newname.c_str());
    }
}
void resize_ratio11(string file_extension, int ratio){
    Image image(file_extension);
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
    cout << "you want to save the new image or apply the filter in the same image?\n";
    cout << "1) same image.\n";
    cout << "2) new image.\n";
    char choice2;
    cin >> choice2;
    
    while(choice2 != '1' && choice2 != '2'){              //// validation test
        cout << "invalid choice, please try again.\n";
        cin >> choice2;
    }
   
    if(choice2 =='1'){                              //// incase the user choose to save the image in the same file as old one
        cin.ignore();
        cout << "the image has been updated.\n";
        resized_image.saveImage(file_extension);
        system(file_extension.c_str());
    }
    else if(choice2 =='2'){                          //// incase the user choose to create a new file to the new image
        string newname;
        cout << "please enter the name of the new file 'hint: with the extension'\n";
        cin.ignore();
        getline(cin, newname);
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(newname)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, newname);
            }
        }
        resized_image.saveImage(newname);
        cout << "new image created succesfully.\n";
        system(newname.c_str());
    }
}

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
    cout << "you want to save the new image or apply the filter in the same image?\n";
    cout << "1) same image.\n";
    cout << "2) new image.\n";
    char choice2;
    cin >> choice2;
    
    while(choice2 != '1' && choice2 != '2'){              //// validation test
        cout << "invalid choice, please try again.\n";
        cin >> choice2;
    }
   
    if(choice2 =='1'){                              //// incase the user choose to save the image in the same file as old one
        cin.ignore();
        cout << "the image has been updated.\n";
        blurred_image.saveImage(file_extension);
        system(file_extension.c_str());
    }
    else if(choice2 =='2'){                          //// incase the user choose to create a new file to the new image
        string newname;
        cout << "please enter the name of the new file 'hint: with the extension'\n";
        cin.ignore();
        getline(cin, newname);
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(newname)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, newname);
            }
        }
        blurred_image.saveImage(newname);
        cout << "new image created succesfully.\n";
        system(newname.c_str());
    }
}

void sunlight13(string file_extension){
     
    Image image(file_extension);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            
            image(i, j, 0) = min(255, image(i, j, 0) + 40); // Increase red channel
            image(i, j, 1) = min(255, image(i, j, 1) + 30); // Increase green channel
            image(i, j, 2) = max(0, image(i, j, 2) - 10); // Decrease blue channel
        }
    }

    cout << "you want to save the new image or apply the filter in the same image?\n";
    cout << "1) same image.\n";
    cout << "2) new image.\n";
    char choice2;
    cin >> choice2;
    
    while(choice2 != '1' && choice2 != '2'){              //// validation test
        cout << "invalid choice, please try again.\n";
        cin >> choice2;
    }
   
    if(choice2 =='1'){                              //// incase the user choose to save the image in the same file as old one
        cin.ignore();
        cout << "the image has been updated.\n";
        image.saveImage(file_extension);
        system(file_extension.c_str());
    }
    else if(choice2 =='2'){                          //// incase the user choose to create a new file to the new image
        string newname;
        cout << "please enter the name of the new file 'hint: with the extension'\n";
        cin.ignore();
        getline(cin, newname);
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(newname)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, newname);
            }
        }
        image.saveImage(newname);
        cout << "new image created succesfully.\n";
        system(newname.c_str());
    }
}
 
void purple16(string file_extension) {
  Image image(file_extension);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            
            image(i, j, 0) = min(255, image(i, j, 0) + 60); // red channel
            image(i, j, 1) = max(0, image(i, j, 1) - 0); //  green channel
            image(i, j, 2) = min(255, image(i, j, 2) + 40); // blue channel
        }
    }

    cout << "you want to save the new image or apply the filter in the same image?\n";
    cout << "1) same image.\n";
    cout << "2) new image.\n";
    char choice2;
    cin >> choice2;
    
    while(choice2 != '1' && choice2 != '2'){              //// validation test
        cout << "invalid choice, please try again.\n";
        cin >> choice2;
    }
   
    if(choice2 =='1'){                              //// incase the user choose to save the image in the same file as old one
        cin.ignore();
        cout << "the image has been updated.\n";
        image.saveImage(file_extension);
        system(file_extension.c_str());
    }
    else if(choice2 =='2'){                          //// incase the user choose to create a new file to the new image
        string newname;
        cout << "please enter the name of the new file 'hint: with the extension'\n";
        cin.ignore();
        getline(cin, newname);
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(newname)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, newname);
            }
        }
        image.saveImage(newname);
        cout << "new image created succesfully.\n";
        system(newname.c_str());
    }
}

void infrared17(string file_extension){
Image image (file_extension);

    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            
            image(i, j, 0) = 255;
            image(i, j, 1) = 255 - image(i,j,1);
            image(i, j, 2) = 255 - image(i,j,2);
        }
    }
    
    cout << "you want to save the new image or apply the filter in the same image?\n";
    cout << "1) same image.\n";
    cout << "2) new image.\n";
    char choice2;
    cin >> choice2;
    
    while(choice2 != '1' && choice2 != '2'){              //// validation test
        cout << "invalid choice, please try again.\n";
        cin >> choice2;
    }
   
    if(choice2 =='1'){                              //// incase the user choose to save the image in the same file as old one
        cin.ignore();
        cout << "the image has been updated.\n";
        image.saveImage(file_extension);
        system(file_extension.c_str());
    }
    else if(choice2 =='2'){                          //// incase the user choose to create a new file to the new image
        string newname;
        cout << "please enter the name of the new file 'hint: with the extension'\n";
        cin.ignore();
        getline(cin, newname);
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(newname)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, newname);
            }
        }
        image.saveImage(newname);
        cout << "new image created succesfully.\n";
        system(newname.c_str());
    }
}

int main(){

    string file_extension;
    cout << "Welcome to filters program\n";         //// printing welcome message
    cout << "Please enter the image name with file extension that you want to edit (or 'exit'):\n";   
    getline(cin, file_extension);
   
    while (true){                                  //// while loop to keep going till the user enter exit
        
        bool isValidFilename = false;
        while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(file_extension) || file_extension == "exit"){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, file_extension);
            }
        }
        
        if (file_extension == "exit") {            //// check if the user want to end the program or not
            cout << "see you soon.\n";
            break;
        }

        cout << "now you need to choose a filter to apply.\n";   //// printing the menu of the filters to make the user choose
        cout << "1) Grayscale Conversion filter.\n" ;
        cout << "2) Black and White filter.\n" ;
        cout << "3) Invert Image filter.\n" ;
        cout << "4) Merge Images filter.\n" ;
        cout << "5) Flip Image filter.\n" ;
        cout << "6) Rotate image filter.\n";
        cout << "7) Darken and Lighten Image filter.\n";
        cout << "8) Crop image filter.\n";
        cout << "9) Frame image filter.\n";
        cout << "10) Detect Image Edges filter.\n";
        cout << "11) Resizing image filter.\n";
        cout << "12) Blur image filter.\n";
        cout << "13) Infrared image filter.\n";
        cout << "14) Sunlight image filter.\n";
        cout << "15) Purple image filter.\n";
        int choice;
        cin >> choice;
        

        while (choice < 1 || choice > 15){               //// check the validation of the input
            cout << "invalid choice, please try again.\n";
            cin >> choice;
        }

        if(choice == 1){                                     //// incase the user choose the 1st filter
            cout << "you choose to apply Grayscale Conversion filter.\n";
            cout << "the filter applied succesfully.\n";
            grayscale1(file_extension);                           //// calling the function
            
        }

        if(choice == 2){                                     //// incase the user choose the 2nd filter
            cout << "you choose to apply black and white filter.\n";
            cout << "the filter applied succesfully.\n";
            black_white2(file_extension);                           //// calling the function
        }

        if(choice == 3){                                     //// incase the user choose the 3rd filter
            cout << "you choose to apply Invert Image filter.\n";
            cout << "the filter applied succesfully.\n";
            Invert3(file_extension);                           //// calling the function
        }

        if(choice == 4){                                     //// incase the user choose the 4th filter
            cout << "you choose to apply Merge Images filter.\n";
            cout << "please enter the 2nd image to merge.\n";
            string image2_name;
            int width , height;
            cin.ignore();
            getline(cin,image2_name);
            bool isValidFilename = false;
            while (!isValidFilename){                 //// while loop to check if the input is valid image file name with extension
            if(hasImageExtension(image2_name)){
                isValidFilename = true;
            } 
            else{
                cout << "something wrong with the input you enterd, Please try again.\n" ;
                getline(cin, image2_name);
            }
            }
            cout << "enter the width and the height of the new image\n";
            cin >> width >> height;
            merge_two_images4(file_extension,image2_name,width,height);
            cout << "the filter applied succesfully.\n";
        }

        if(choice == 5){                                     //// incase the user choose the 5th filter
            cout << "you choose to apply Flip Image filter.\n";
            cout << "do you want to flip the image horizontally or vertically.\n";  //// menu to make the user choose which flip he wants
            cout << "1) Horizontal\n";
            cout << "2) Vertical\n";
            char choice2;
            cin >> choice2;
            while(choice2 != '1' && choice2 != '2'){               /// check the validation of the input
                cout << "invalid choice, please try again.\n";
                cin >> choice2;
            }
            if(choice2 =='1'){                               //// incase the user choose to flip horizontally
                cout << "you choose to flip horizontally.\n";
                fliph5(file_extension);                           //// calling the function
            }
            else{
                cout << "you choose to flip vertically.\n";       //// incase the user choose to flip vertically
                flipv5(file_extension);                           //// calling the function
            }
        }

        if(choice == 6){                                    
            cout << "you choose to apply Flip Image filter.\n";
            cout << "do you want to flip the image horizontally or vertically.\n";  //// menu to make the user choose which rptate angle he wants
            cout << "1) 90 Degree.\n";
            cout << "2) 180 Degree.\n";
            cout << "3) 270 Degree.\n";
            char choice2;
            cin >> choice2;
            while(choice2 != '1' && choice2 != '2' && choice2 != '3'){               /// check the validation of the input
                cout << "invalid choice, please try again.\n";
                cin >> choice2;
            }
            if(choice2 =='1'){                               
                cout << "you choose to rotate 90 degree.\n";
                rotateImage90_6(file_extension);
            }
            else if(choice2 =='2'){
                cout << "you choose to rotate 180 degree.\n";       
                rotateImage180_6(file_extension);
            }
            else{
                cout << "you choose to rotate 270 degree.\n";
                rotateImage270_6(file_extension);
            }
        }

        if(choice == 7){                                    
            cout << "you choose to apply Darken and Lighten Image filter.\n";
            cout << "do you want to lighten the image or darken the image.\n";  //// menu to make the user choose which rptate angle he wants
            cout << "1) lighten.\n";
            cout << "2) darken.\n";
            char choice2;
            cin >> choice2;
            while(choice2 != '1' && choice2 != '2'){               /// check the validation of the input
                cout << "invalid choice, please try again.\n";
                cin >> choice2;
            }
            if(choice2 =='1'){                               
                cout << "you choose to lighten the image\n";
                lightening7(file_extension);
            }
            else if(choice2 =='2'){
                cout << "you choose to darken the image\n";       
                darkening7(file_extension);
            }
        }

        if(choice == 8){
            int start_x,start_y,width,height;
            cout << "you choose to crop image,\n";
            cout << "please enter the starting point to start from: \n";
            cin >> start_x >> start_y;
            cout << "please enter the dimension: \n";
            cin >> width >> height;
            crop8(file_extension,start_x,start_y,width,height);
        }
        
        if(choice == 9){                                   
            cout << "you choose to apply frame to the Image.\n";
            cout << "do you want to apply the simple frame or the fancy frame ?\n";
            cout << "1) simple frame.\n";
            cout << "2) fancy frame.\n";
            char choice2;
            cin >> choice2;
            while(choice2 != '1' && choice2 != '2'){               /// check the validation of the input
                cout << "invalid choice, please try again.\n";
                cin >> choice2;
            }
            if(choice2 == '1'){
                cin.ignore();
                cout << "you choose to apply the simple filter.\n";
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
                cin.ignore();
                frame_color(framecolor, choice3); 
                frame_simple9(file_extension, thickness, framecolor);
            }

            if(choice2 == '2'){
                cin.ignore();
                cout << "you choose to apply the fancy filter.\n";
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
                cin.ignore();
                frame_color(framecolor, choice3); 
                frame_fancy9(file_extension, thickness, framecolor);
            }
        }

        if(choice == 10){                                   
            cout << "you choose to apply Detect Image Edges filter.\n";
            cout << "the filter applied succesfully.\n";
            detectBoundaries10(file_extension);                           //// calling the function
        }
        
        if(choice == 11){
            cout << "you choose to apply resizing image filter\n";
            cout << "you want to resize the image using new dimension or ratio ?\n";
            cout << "1) new dimension.\n";
            cout << "2) ratio.\n";
            char choice2;
            cin >> choice2;
            while(choice2 != '1' && choice2 != '2'){               /// check the validation of the input
                cout << "invalid choice, please try again.\n";
                cin >> choice2;
            }
            if(choice2 =='1'){                               
                cout << "please enter the new dimensions\n";
                int width,height;
                cout <<"width: ";
                cin >> width;
                cout << "height: ";
                cin >> height;
                resize_dimension11(file_extension,width,height);
            }
            else{
                cout << "please enter the ratio: ";
                int ratio;
                cin >> ratio;
                resize_ratio11(file_extension,ratio);
            }
        }
        
        if(choice == 12){
            cout << "you choose to blur image filter.\n";
            blur12(file_extension);
        }

        if(choice == 13){
            cout << "you choose to apply infrared image filter.\n";
            infrared17(file_extension);
        }

        if(choice == 14){
            cout << "you choose to apply sunlight image filter.\n";
            sunlight13(file_extension);
        }

        if(choice == 15){
            cout << "you choose to apply purple image filter.\n";
            purple16(file_extension);
        }

        cout << "If you want to continue write the name of the image you want to edit with extension\n";
        cout << "If you want to exit type 'exit'\n";            //// asking the user if he want to continue or to exit
        getline(cin, file_extension);
        
  
    }
    return 0 ;
}
