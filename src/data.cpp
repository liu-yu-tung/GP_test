#include "../include/data.hpp"
Shape::Shape(int _lengthOfBuffer):lengthOfBuffer(_lengthOfBuffer){};

Shape::Shape(int _lengthOfBuffer, int _widthOfBuffer):
    lengthOfBuffer(_lengthOfBuffer), widthOfBuffer(_widthOfBuffer){};

int Shape::getLength() const{
    return lengthOfBuffer;
};
    
int Shape::getWidth() const{
    if(Const::dimensionOfBuffer==1){
        std::cerr << "Cannot get the width of ONE dimensional vector" << std::endl;
        return -1;
    }
    return widthOfBuffer;
};

void Shape::getShape() const{
    std::cout << "Buffer's Shape: ";
    if (Const::dimensionOfBuffer == 1) 
        std::cout << "length=" << lengthOfBuffer << std::endl;
    else
        std::cout << "length=" << lengthOfBuffer << ", width=" << widthOfBuffer << std::endl;

};



//constructor of differenet type
bufferInt1D::bufferInt1D(){
    buffer.resize(Const::shapeOfBuffer.getLength(), 0);
};

bufferInt2D::bufferInt2D(){
    buffer.resize(Const::shapeOfBuffer.getLength(), std::vector<int>(Const::shapeOfBuffer.getWidth(), 0));
};

bufferFloat1D::bufferFloat1D(){
    buffer.resize(Const::shapeOfBuffer.getLength(), 0.0);
};

bufferFloat2D::bufferFloat2D(){
    buffer.resize(Const::shapeOfBuffer.getLength(), std::vector<float>(Const::shapeOfBuffer.getWidth(), 0.0));
};

//show function of different type
void bufferInt1D::show(){
    std::cout << "bufferInt1D: ";
    for(int item: buffer) std::cout << item << " ";
    std::cout << std::endl;
};

void bufferFloat1D::show(){
    std::cout << "bufferFloat1D: ";
    for(int item: buffer) std::cout << item << " ";
    std::cout << std::endl;
};

void bufferInt2D::show(){
    std::cout << "bufferInt2D:\n";
    for(std::vector<int> row: buffer){
        for(int item: row)std::cout << item << " ";
        std::cout << std::endl;
    }
};

void bufferFloat2D::show(){
    std::cout << "bufferFloat2D:\n";
    for(std::vector<float> row: buffer){
        for(float item: row)std::cout << item << " ";
        std::cout << std::endl;
    }
};

//return value of buffer
int &bufferBase::returnIntValue(std::vector<int> &){
    std::cerr << "In int &bufferBase::returnIntValue(std::vector<int> &).This buffer doesn't have Int buffer.\n";
};

float &bufferBase::returnFloatValue(std::vector<int> &){
    std::cerr << "In float &bufferBase::returnFloatValue(std::vector<int> &).This buffer doesn't have Float buffer.\n";
};

int &bufferInt1D::returnIntValue(std::vector<int> &index){
    if(index.size()!=1) std::cerr << "In void *bufferInt1D::returnValue(std::vector<int> &index), index number mismatched\n";
    return buffer[index[0]];
};

int &bufferInt2D::returnIntValue(std::vector<int> &index){
    if(index.size()!=2) std::cerr << "In void *bufferInt2D::returnValue(std::vector<int> &index), index number mismatched\n";
    return buffer[index[0]][index[1]];
};

float &bufferFloat1D::returnFloatValue(std::vector<int> &index){
    if(index.size()!=1) std::cerr << "In void *bufferFloat1D::returnValue(std::vector<int> &index), index number mismatched\n";
    return buffer[index[0]];
};

float &bufferFloat2D::returnFloatValue(std::vector<int> &index){
    if(index.size()!=2) std::cerr << "In void *bufferFloat2D::returnValue(std::vector<int> &index), index number mismatched\n";
    return buffer[index[0]][index[1]];
};

//show basic information about data
void GETINFO(){
    std::cout << "::::::::::INFO of BUFFER::::::::::" << std::endl;
    std::cout << "Dimension of Buffer: " << Const::dimensionOfBuffer << std::endl;
    std::cout << "Type of Buffer: " << Const::typeOfBuffer << std::endl;
    Const::shapeOfBuffer.getShape();
    std::cout << "::::::::::::::::::::::::::::::::::" << std::endl;
};

Data::Data(){
    if(Const::dimensionOfBuffer==1){
        if(Const::typeOfBuffer==Int) bufferPtr = new bufferInt1D;
        else if(Const::typeOfBuffer==Float) bufferPtr = new bufferFloat1D;
    }
    else if(Const::dimensionOfBuffer==2)  {
        if(Const::typeOfBuffer==Int) bufferPtr = new bufferInt2D;
        else if(Const::typeOfBuffer==Float) bufferPtr = new bufferFloat2D;
    }
};

Data::~Data(){
    delete bufferPtr;
};

void Data::show(){
    bufferPtr->show();
};


int &Data::returnIntValue(std::vector<int> &index){
    return bufferPtr->returnIntValue(index);
}; 

float &Data::returnFloatValue(std::vector<int> &index){
    return bufferPtr->returnFloatValue(index);
}; 

