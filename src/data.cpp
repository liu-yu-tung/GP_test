#include "../include/data.hpp"

Shape::Shape(int _lengthOfBuffer):lengthOfBuffer(_lengthOfBuffer){};


Shape::Shape(int _lengthOfBuffer, int _widthOfBuffer):
    lengthOfBuffer(_lengthOfBuffer), widthOfBuffer(_widthOfBuffer){};

int Shape::getLength() const{
    return lengthOfBuffer;
};
    
int Shape::getWidth() const{
    if(dimensionOfBuffer==1){
        std::cerr << "Cannot get the width of ONE dimensional vector" << std::endl;
        return -1;
    }
    return widthOfBuffer;
};

void Shape::getShape() const{
    std::cout << "Buffer's Shape: ";
    if (dimensionOfBuffer == 1) 
        std::cout << "length=" << lengthOfBuffer << std::endl;
    else
        std::cout << "length=" << lengthOfBuffer << ", width=" << widthOfBuffer << std::endl;

};

void GETINFO(){
    std::cout << "::::::::::INFO of BUFFER::::::::::" << std::endl;
    std::cout << "Dimension of Buffer: " << dimensionOfBuffer << std::endl;
    std::cout << "Type of Buffer: " << typeOfBuffer << std::endl;
    shapeOfBuffer.getShape();
    std::cout << "::::::::::::::::::::::::::::::::::" << std::endl;
};

//show funciton of data
void Data::show(std::vector<int> &bufferInt1D){
    for (int item:bufferInt1D)
        std::cout << item << " ";
    std::cout << std::endl;
};
void Data::show(std::vector<std::vector<int>> &bufferInt2D){
    for (auto row:bufferInt2D){
        for (int item:row)
            std::cout << item << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void Data::show(std::vector<float> &bufferFloat1D){
    for (float item:bufferFloat1D)
        std::cout << item << " ";
    std::cout << std::endl;
};

void Data::show(std::vector<std::vector<float>> &bufferFloat2D){
    for (auto row:bufferFloat2D){
        for (auto item:row)
            std::cout << item << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

//Based on global setting, setup the data buffer
Data::Data(){
    if(typeOfBuffer==Int){
        if(dimensionOfBuffer==1) bufferInt1D.resize(shapeOfBuffer.getLength(), 0);
        else if(dimensionOfBuffer==2)
            bufferInt2D.resize(shapeOfBuffer.getWidth(), std::vector<int>(shapeOfBuffer.getLength(), 0));
    }
    else if(typeOfBuffer==Float){
        if(dimensionOfBuffer==1) bufferFloat1D.resize(shapeOfBuffer.getLength(), 0.0);
        else if(dimensionOfBuffer==2)
            bufferFloat2D.resize(shapeOfBuffer.getWidth(), std::vector<float>(shapeOfBuffer.getLength(), 0.0));
    }
};

void Data::showBuffer(){
    if(typeOfBuffer==Int){
        if(dimensionOfBuffer==1) show(bufferInt1D);
        else if(dimensionOfBuffer==2) show(bufferInt2D);
    }
    else if(typeOfBuffer==Float){
        if(dimensionOfBuffer==1) show(bufferFloat1D);
        else if(dimensionOfBuffer==2) show(bufferFloat2D);
    }
};



