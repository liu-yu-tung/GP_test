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
    static const Shape shapeOfBuffer = Shape(3, 3);
    
    static const int maximumTreeHeight = 2;
    
    enum growMethod{
        grow,
        full,
        half_half
    };
    static const growMethod growMethodGlobal = growMethod::full; 

    enum functionSet{
        Max2,
        Swap,
        NUM_ENTRIES
    };
    static const int functionSetNumber = static_cast<int>(functionSet::NUM_ENTRIES-1);
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
friend class Function;
public:
    Data();
    Data(const Data &);
    ~Data();

    int getIndexUseNumber();
    std::vector<int> indexUse;

    void show();
    void set(std::vector<int> &, int);
    void set(std::vector<int> &, float);
    void setAvailable(int);
    void setAvailable(int, int);

    int &getIntValue(std::vector<int> &, int); 
    float &getFloatValue(std::vector<int> &, int);


private:
    bufferBase* bufferPtr;
    int indexUseNumber;

    std::vector<bool> isIndexInit1D;
    std::vector<std::vector<bool>> isIndexInit2D;
};

