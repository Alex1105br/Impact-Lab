#include <iostream>
#include <fstream>

/*

int red = 0;
int green = 0;
int blue = 0; 

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            red = i * 50;
            green  = j * 10;
            blue = (i + j) * 15;

            imageOut << red << " " << green << " " << blue << " ";
        }
        imageOut << std::endl;
    }
*/

using namespace std;

int main(){
    
    cout << "Impact Lab PPM\n";

    ofstream imagein;
    ifstream imageout;

    imagein.open("C:/Users/Alex Viana/Desktop/impact_lab/imagem.ppm");


    if(imagein.is_open()){
        cout << "Header" << endl;
        imagein << "P3" << endl;
        imagein << "3 2" << endl;
        imagein << "255" << endl;
    }


    cout << "Task 3: PPM Body" << endl;

    imagein << "255 0 0" << endl; // red
    imagein << "0 255 0" << endl; // G
    imagein << "0 0 255" << endl; // B
    imagein << "255 255 0" << endl; // Y
    imagein << "255 255 255" << endl; // W
    imagein << "0 0 0" << endl; // B

    imagein.close();
    cout << "End"<<endl;
    return 0;
}