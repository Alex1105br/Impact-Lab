#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

int main(){

    clock_t start = clock();
    ifstream image_read;

    image_read.open("../Heterogeneous Architectures/apollo.ppm");

    ofstream image_write;

    image_write.open("../Heterogeneous Architectures/new_image.ppm");

    string type = "", width = "", height = "", RGBMax = "";

    image_read >> type;
    image_read >> width;
    image_read >> height;
    image_read >> RGBMax;


    string red = "", green = "", blue = "";

    image_write << type << endl;
    image_write << width << " " << height << endl;
    image_write << RGBMax << endl;

    while(!image_read.eof()){
        image_read >> red;
        image_read >> green;
        image_read >> blue;

        image_write << red << " " << green << " " << blue << " " << endl;
    }



    image_read.close();
    image_write.close();


    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "Tempo de execucao: " << elapsed_time << " segundos" << std::endl;
    return 0;
}