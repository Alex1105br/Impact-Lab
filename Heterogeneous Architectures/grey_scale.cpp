#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <stdint.h>

#define STB_IMAGE_IMPLEMENTATION
#include "include/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "include/stb_image_write.h"

#define CHANNEL_NUM 4

using namespace std;

int main(){
    int width, height, bpp;
    clock_t start = clock();

    unsigned char* image = stbi_load("../Heterogeneous Architectures/londres.jpg", &width, &height, &bpp, CHANNEL_NUM);

    if(image == NULL){
        cout << "Error in loading the image\n";
        exit(1);
    }

    // Grey scale filter

    for(int i=0; i<width*height*4; i+=4){
        unsigned char grey = image[i] * 0.2126 + image[i+1] * 0.7152 + image[i+2] * 0.0722;
        image[i] = grey; //red
        image[i+1] = grey; //green
        image[i+2] = grey; //blue
    }

    cout << "Loaded image with a widht of "<< width << " a height of "<< height << " Channel number "<< CHANNEL_NUM << endl;

    stbi_write_png("../Heterogeneous Architectures/londres_grey.jpg", width,height, CHANNEL_NUM, image, width * CHANNEL_NUM);



    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

    cout << "Runtime: " << elapsed_time << " seconds" << std::endl;
    
    stbi_image_free(image);

}
