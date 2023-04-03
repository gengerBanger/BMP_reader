#include <iostream>
#include <fstream>
typedef unsigned __int16 int2;

class BMP{
private:
        char Type_1,Type_2;
        int Size_f;
        int Reserved;
        int OffBits;
        int Size_s;
        int Width;
        int Height;
        int2 PixelDensity;
    const char * fName;
public:
    BMP(const char * name){
        fName = name;
    }
    void readFile(){
        std::ifstream file (fName, std :: ios ::binary);
        file.read((char *)&Type_1, sizeof(Type_1));
        file.read((char *)&Type_2, sizeof(Type_2));
        file.read((char *)&Size_f, sizeof(Size_f));
        file.read((char *)&Reserved, sizeof(Reserved));
        file.read((char *)&OffBits, sizeof(OffBits));
        file.read((char *)&Size_s, sizeof(Size_s));
        file.read((char *)&Width, sizeof(Width));
        file.read((char *)&Height, sizeof(Height));
        file.seekg(sizeof(int2));
        file.read((char *)&PixelDensity, sizeof(PixelDensity));
        file.close();
    }
    void outInfo(){
        std :: cout  << "Type : " << Type_1  <<  Type_2 << '\n';
        std :: cout  << "Size of file : " << Size_f / 1024 << " KB\n";
        std :: cout  << "Reserved : " << Reserved << '\n';
        std :: cout  << "OffBits : " << OffBits << '\n';
        std :: cout  << "Size of struct : " << Size_s << " B \n";
        std :: cout  << "Width : " << Width << '\n';
        std :: cout  << "Height : " << Height << '\n';
        std :: cout  << "Number of colors : " << PixelDensity << '\n';
    }

};
int main() {
    const char * Fname = R"(C:\Users\aleks\CLionProjects\bmpReader\for reader.bmp)";

    BMP newBMP(Fname);

    newBMP.readFile();

    newBMP.outInfo();

    return 0;
}
