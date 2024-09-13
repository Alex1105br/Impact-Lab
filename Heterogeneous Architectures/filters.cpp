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





void negative_filter(unsigned char* image, int width, int height){
    
    for(int i=0; i<width*height*4; i+=4){
        //unsigned char negative = (255 - image[i]) + (255 - image[i+1])  + (255 - image[i+2]);
        image[i] = 255-image[i]; //red
        image[i+1] = 255-image[i+1]; //green
        image[i+2] = 255-image[i+2]; //blue
    }

    cout << "Loaded image with a widht of "<< width << " a height of "<< height << " Channel number "<< CHANNEL_NUM << endl;

    stbi_write_png("../Heterogeneous Architectures/dead_cells_negative.jpg", width,height, CHANNEL_NUM, image, width * CHANNEL_NUM);

    //return image;
}


void grey_scale(unsigned char* image, int width, int height){
    for(int i=0; i<width*height*4; i+=4){
        unsigned char grey = image[i] * 0.2126 + image[i+1] * 0.7152 + image[i+2] * 0.0722;
        image[i] = grey; //in the channel red
        image[i+1] = grey; //in the channel green
        image[i+2] = grey; //in the channel blue
    }

    cout << "Loaded image with a widht of "<< width << " a height of "<< height << " Channel number "<< CHANNEL_NUM << endl;

    stbi_write_png("../Heterogeneous Architectures/dead_cells_grey.jpg", width,height, CHANNEL_NUM, image, width * CHANNEL_NUM);
}



void red_filter(unsigned char* image, int width, int height){

    for(int i = 0; i < width * height * 4; i += 4){
        if(!(image[i] >= 128 && image[i+1] <= 127 && image[i+2] <= 127)){
            // Converte para escala de cinza
            unsigned char grey = image[i] * 0.2126 + image[i+1] * 0.7152 + image[i+2] * 0.0722;
            image[i] = grey;   // canal vermelho
            image[i+1] = grey; // canal verde
            image[i+2] = grey; // canal azul
        }
    }

    cout << "Loaded image with a width of " << width << " a height of " << height << " Channel number " << CHANNEL_NUM << endl;

    stbi_write_png("../Heterogeneous Architectures/samurai_red.jpg", width, height, CHANNEL_NUM, image, width * CHANNEL_NUM);
}



int main(){

    int width, height, bpp;
    int filter_number;

    

    unsigned char* image = stbi_load("../Heterogeneous Architectures/samurai.jpg", &width, &height, &bpp, CHANNEL_NUM);

    if(image == NULL){
        cout << "Error in loading the image\n";
        exit(1);
    }
    

    cout << "Choose the filter number:" << endl<< "1-Grey Scale" <<  endl << "2-Negative Filter "<< endl << "3-Red Filter " <<endl;
    cin >> filter_number;

    clock_t start = clock();

    if(filter_number==1){
        // Grey scale filter

        grey_scale(image,width,height);

    }if(filter_number==2){

        //Negative Filter

       negative_filter(image,width,height);
    }if(filter_number==3){
        red_filter(image,width,height);
    }

    

    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

    cout << "Runtime: " << elapsed_time << std::endl;
    
    stbi_image_free(image);

}