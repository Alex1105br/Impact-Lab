#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <stdint.h>



#define STB_IMAGE_IMPLEMENTATION
#include "include/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "include/stb_image_write.h"

#define CHANNEL_NUM 3

using namespace std;

int main(){
    clock_t start = clock();

    int width, height, bpp;

    unsigned char* rgb_image = stbi_load("../Heterogeneous Architectures/londres.jpg", &width, &height, &bpp, CHANNEL_NUM);

    if(rgb_image == NULL){
        cout << "Error in loading the image\n";
        exit(1);
    }

    cout << "Loaded image with a widht of "<< width << " a height of "<< height << " Channel number "<< CHANNEL_NUM << endl;

    stbi_write_png("../Heterogeneous Architectures/londres_imageOut.png", width,height, CHANNEL_NUM, rgb_image, width * CHANNEL_NUM);

    stbi_image_free(rgb_image);

    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "Runtime: " << elapsed_time << " seconds" << std::endl;

    return 0;
}