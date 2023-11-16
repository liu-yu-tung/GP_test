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
        for(int item: row) std::cout << item << " ";
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
int &bufferBase::returnIntValue(std::vector<int> &index){
    if(index.size()!=1) std::cerr << "In int &bufferBase::returnIntValue(std::vector<int> &index), index number mismatched\n";
};

float &bufferBase::returnFloatValue(std::vector<int> &index){
    if(index.size()!=1) std::cerr << "In float &bufferBase::returnFloatValue(std::vector<int> &index), index number mismatched\n";
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

Data::Data():
    isIndexInit1D(std::vector<bool>(Const::shapeOfBuffer.getLength(), false)),
    isIndexInit2D(std::vector<std::vector<bool>>(Const::shapeOfBuffer.getLength(), std::vector<bool>(Const::shapeOfBuffer.getWidth(), false))),
    indexUseNumber(0)
{
    if(Const::dimensionOfBuffer==1){
        if(Const::typeOfBuffer==Int) bufferPtr = std::make_unique<bufferInt1D>();
        else if(Const::typeOfBuffer==Float) bufferPtr = std::make_unique<bufferFloat1D>();;
    }
    else if(Const::dimensionOfBuffer==2)  {
        if(Const::typeOfBuffer==Int) bufferPtr = std::make_unique<bufferInt2D>();
        else if(Const::typeOfBuffer==Float) bufferPtr = std::make_unique<bufferFloat2D>();;
    }
};

Data::Data(const Data &givenData):
isIndexInit1D(givenData.isIndexInit1D), isIndexInit2D(givenData.isIndexInit2D), indexUseNumber(givenData.indexUseNumber), indexUse(givenData.indexUse)
{
    std::vector<int> index;
    if(Const::dimensionOfBuffer==1){  
        if(Const::typeOfBuffer==Int) bufferPtr = std::make_unique<bufferInt1D>();
        else if(Const::typeOfBuffer==Float) bufferPtr = std::make_unique<bufferFloat1D>();
        for(int i=0; i<indexUseNumber; i++){
            index.assign(indexUse.begin()+i, indexUse.begin()+i+1);
            bufferPtr->returnIntValue(index) = givenData.bufferPtr->returnIntValue(index);
        }
    }
    else if(Const::dimensionOfBuffer==2) {   
        if(Const::typeOfBuffer==Int) bufferPtr = std::make_unique<bufferInt2D>();
        else if(Const::typeOfBuffer==Float) bufferPtr = std::make_unique<bufferFloat2D>();
        for(int i=0; i<indexUseNumber; i++){
            index.assign(indexUse.begin()+2*i, indexUse.begin()+2*i+2);
            bufferPtr->returnIntValue(index) = givenData.bufferPtr->returnIntValue(index);
        }
    }
};

int Data::getIndexUseNumber(){
    return indexUseNumber;
};

void Data::show(){
    bufferPtr->show();
};

int &Data::getIntValue(std::vector<int> &index, int order){
    order--;
    std::vector<int> v;
    if(Const::dimensionOfBuffer==1) v.push_back(index[order]);
    else if(Const::dimensionOfBuffer==2) v.assign(index.begin()+2*order, index.begin()+2*order+2);
    return bufferPtr->returnIntValue(v);
}; 

float &Data::getFloatValue(std::vector<int> &index, int order){
    order--;
    std::vector<int> v;
    if(Const::dimensionOfBuffer==1) v.push_back(index[order]);
    else if(Const::dimensionOfBuffer==2) v.assign(index.begin()+2*order, index.begin()+2*order+2);
    return bufferPtr->returnFloatValue(v);
}; 

int &Data::getIntValue(int x){
    std::vector<int> index;
    index.push_back(x);
    return getIntValue(index, 1);                                         
}; 

int &Data::getIntValue(int x, int y){
    std::vector<int> index;
    index.push_back(x);
    index.push_back(y);
    return getIntValue(index, 1);       
}; 

float &Data::getFloatValue(int x){
    std::vector<int> index;
    index.push_back(x);
    return getFloatValue(index, 1);     
};

float &Data::getFloatValue(int x, int y){
    std::vector<int> index;
    index.push_back(x);
    index.push_back(y);
    return getFloatValue(index, 1);    
};
    
void Data::set(std::vector<int> &index, int i){
    bufferPtr->returnIntValue(index) = i;
    if(Const::dimensionOfBuffer==1) setAvailable(index[0]);
    else if(Const::dimensionOfBuffer==2) setAvailable(index[0], index[1]);
};

void Data::set(std::vector<int> &index, float f){
    bufferPtr->returnFloatValue(index) = f;
    if(Const::dimensionOfBuffer==1) setAvailable(index[0]);
    else if(Const::dimensionOfBuffer==2) setAvailable(index[0], index[1]);
};

void Data::set(int index, int i){
    std::vector<int> v;
    v.push_back(index);
    set(v, i);
};

void Data::set(int index, float f){
    std::vector<int> v;
    v.push_back(index);
    set(v, f);
};

void Data::set(int index_x, int index_y, int i){
    std::vector<int> v;
    v.push_back(index_x);
    v.push_back(index_y);
    set(v, i);
};

void Data::set(int index_x, int index_y, float f){
    std::vector<int> v;
    v.push_back(index_x);
    v.push_back(index_y);
    set(v, f);
};

void Data::setAvailable(int i){
    if(!isIndexInit1D[i]){
        indexUseNumber++;
        indexUse.push_back(i);
        isIndexInit1D[i] = true;
    }
};  

void Data::setAvailable(int i, int j){
    if(!isIndexInit2D[i][j]){
        indexUseNumber++;
        indexUse.push_back(i);
        indexUse.push_back(j);
        isIndexInit2D[i][j] = true;
    }
};  