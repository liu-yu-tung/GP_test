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

void Data::show(std::vector<int> &bufferInt1D){
    for (auto item:bufferInt1D)
        std::cout << item << " ";
    std::cout << std::endl;
};
void Data::show(std::vector<std::vector<int>> &bufferInt2D){
    for (auto row:bufferInt2D)
        for (auto item:row)
            std::cout << item << " ";
        std::cout << std::endl;
    std::cout << std::endl;
}
void Data::show(std::vector<float> &bufferFloat1D){
    for (auto item:bufferFloat1D)
        std::cout << item << " ";
    std::cout << std::endl;
};

void Data::show(std::vector<std::vector<float>> &bufferFloat2D){
    for (auto row:bufferFloat2D)
        for (auto item:row)
            std::cout << item << " ";
        std::cout << std::endl;
    std::cout << std::endl;
}

Data::Data(){
    if(typeOfBuffer==Int){
        if(dimensionOfBuffer==1) bufferInt1D.resize(shapeOfBuffer.getLength());
        else if(dimensionOfBuffer==2){
            bufferInt2D.resize(shapeOfBuffer.getWidth());
            for (auto row: bufferInt2D)
                row.resize(shapeOfBuffer.getLength()); 
        }
    }
    else if(typeOfBuffer==Float){
        if(dimensionOfBuffer==1) bufferFloat1D.resize(shapeOfBuffer.getLength());
        else if(dimensionOfBuffer==2){
            bufferFloat2D.resize(shapeOfBuffer.getWidth());
            for (auto row: bufferFloat2D)
                row.resize(shapeOfBuffer.getLength()); 
        }
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



