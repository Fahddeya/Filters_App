#include <iostream>
#include "Image_Class.h"

using namespace std;

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
  
    image2.saveImage("test.jpg");

}


int main(){

   string file_extension; 
   int start_x, start_y, width, height;
   cin >> file_extension >> start_x >> start_y >> width >> height;
   crop8(file_extension, start_x, start_y, width, height); 
}