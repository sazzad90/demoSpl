#include <bits/stdc++.h>
#include "header.h"
#pragma once
#include<fstream>

void readImage(char* path){
    std::ifstream file;
    file.open(path , std::ios::in | std::ios::binary);

    if(!file.is_open()){
        std:: cout<<"File cannot be read"<<std::endl;
    }

    file.read(reinterpret_cast<char*>(fileHeader),fileHeaderSize);
    file.read(reinterpret_cast<char*>(infoHeader),infoHeaderSize);

    int fileSize=fileHeader[2]+(fileHeader[3]<<8)+(fileHeader[4]<<16)+(fileHeader[5]<<24);
    int width=infoHeader[4]+(infoHeader[5]<<8)+(infoHeader[6]<<16)+(infoHeader[7]<<24);
    int height=infoHeader[8]+(infoHeader[9]<<8)+(infoHeader[10]<<16)+(infoHeader[11]<<24);

    const int paddingAmount=((4-(width*3)%4)%4);

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){

            unsigned char color[3];
            file.read(reinterpret_cast<char*>(color),3);

            pixels[i*width+j][0] = static_cast<float>(color[2])/255.0f;
            pixels[i*width+j][1] = static_cast<float>(color[1])/255.0f;
            pixels[i*width+j][2] = static_cast<float>(color[0])/255.0f;
        }
        file.ignore(paddingAmount);
    }
    file.close();
}
