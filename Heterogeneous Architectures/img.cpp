#include <iostream>
#include <fstream>

using namespace std;

int main(){
    
    fstream image;
    fstream new_image;

    image.open("../Heterogeneous Architectures/imagem.ppm");
    new_image.open("../Heterogeneous Architectures/new_image.ppm");

    if(image.is_open()){
        cout << "Header" << endl;

        image << "P3" << endl;
        image << "250 250" << endl; //image size
        image << "255" << endl;// Image RGB max


        for(int x=0; x<250; x++){
            for(int y=0; y<250; y++){
                if(x<=125 && y<=125){
                    image << 255 << " " << 0 << " " << 0 <<endl;
                }
                if(x<=125 && y>125){
                    image << 0 << " " << 255 << " " << 0 <<endl;
                }
                if(x>125 && y<=125){
                    image << 0 << " " << 0 << " " << 255 <<endl;
                }
                if(x>125 && y>125){
                    image << 255 << " " << 120 << " " << 50 <<endl;
                }
            }
        }
    }

    image.close();
    new_image.close();
    
    return 0;
}