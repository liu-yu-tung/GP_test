#pragma once
#include<vector>
#include<memory>
#include<iostream>
#include<stdio.h>

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

static const int dimensionOfBuffer = 2;
static const DataType typeOfBuffer = Int;
static const Shape shapeOfBuffer(10, 10);

//get basic data info
void GETINFO();


class Data{
    std::vector<int> bufferInt1D;
    std::vector<std::vector<int>> bufferInt2D;
    std::vector<float> bufferFloat1D;
    std::vector<std::vector<float>> bufferFloat2D;
    void show(std::vector<int> &);
    void show(std::vector<std::vector<int>> &);
    void show(std::vector<float> &);
    void show(std::vector<std::vector<float>>&);
public:
    Data();
    void showBuffer();
};

