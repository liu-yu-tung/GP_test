#pragma once
#include "function.hpp"
#include <vector>
#include <memory>
#include <iostream>
#include <stdio.h>

enum DataType{
    Int,
    Float
};

class Shape{
    int lengthOfBuffer;
    int widthOfBuffer;
public:
    Shape(int);
    Shape(int, int);
    int getLength() const;
    int getWidth() const;
    void getShape() const;    
};

//defined constants
namespace Const{
    static const int dimensionOfBuffer = 2;
    static const DataType typeOfBuffer = Int;
    static const Shape shapeOfBuffer = Shape(10, 10);
};

//get basic data info
void GETINFO();

class bufferBase{
public:
    virtual void show() = 0;
    virtual int &returnIntValue(std::vector<int> &);
    virtual float &returnFloatValue(std::vector<int> &);
};

class bufferInt1D: public bufferBase{
public:
    bufferInt1D();
    std::vector<int> buffer;
    void show();
    int &returnIntValue(std::vector<int> &) override;
};

class bufferInt2D: public bufferBase{
public:
    bufferInt2D();
    std::vector<std::vector<int>> buffer;
    void show();
    int &returnIntValue(std::vector<int> &) override;
};

class bufferFloat1D: public bufferBase{
public:
    bufferFloat1D();
    std::vector<float> buffer;
    void show();
    float &returnFloatValue(std::vector<int> &) override; 
};

class bufferFloat2D: public bufferBase{
public:
    bufferFloat2D();
    std::vector<std::vector<float>> buffer;
    void show();
    float &returnFloatValue(std::vector<int> &) override;
};


class Data{
    bufferBase* bufferPtr;
public:
    Data();
    ~Data();
    void show();
    int &returnIntValue(std::vector<int> &); 
    float &returnFloatValue(std::vector<int> &); 
};

