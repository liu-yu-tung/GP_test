#include "function.hpp"

const int Function::arity = -1;

// Swap
const int Swap::arity = 2;
const std::string Swap::functionName = "Swap";
const std::vector<DataType> Swap::inType = {DataType::Int, DataType::Int};
const DataType Swap::outType = DataType::None;


// Loop
const int Loop::arity = 0;
const std::string Loop::functionName = "Loop";

Function::Function(Data* dataPtr_): dataPtr(dataPtr_){};


void Function::addChild(Function *child){
    children.push_back(child);
};

void Function::show(){
    std::cout << "::::::::::::::Show Function:::::::::::::::::" << std::endl;
    std::cout << "Function Name: " << getFunctionName() << std::endl;
    std::cout << "Height: " << height << std::endl;
    std::cout << "Arugument index = ";
    /*
    for(int index: argumentIndex)
        std::cout << index << " ";
    std::cout << std::endl;
    std::cout << "Outputs index = ";
    for(int index: outputIndex)
        std::cout << index << " ";
    */
    std::cout << std::endl;
    std::cout << "::::::::::::::::::::::::::::::::::::::::::::" << std::endl;
};

void Function::setHeight(int h){
    height = h;
};

void Function::setInRecursive(bool state) {
    inRecursive = state;
};

void Function::setListBegin(int begin) {
    listBegin = begin;
};

Swap::Swap(Data *dataptr): Function(dataptr){};

std::string Swap::getFunctionName(){
    return Swap::functionName;
}

void Swap::execution(){
    /*
    int temp; 
    if(Const::typeOfBuffer==Int){
        temp = dataPtr->getIntValue(argumentIndex, 1);
        dataPtr->getIntValue(argumentIndex, 1) = dataPtr->getIntValue(argumentIndex, 2);
        dataPtr->getIntValue(argumentIndex, 2) = temp;
    }   
    else if(Const::typeOfBuffer==Float){
        temp = dataPtr->getFloatValue(argumentIndex, 1);
        dataPtr->getFloatValue(argumentIndex, 1) = dataPtr->getFloatValue(argumentIndex, 2);
        dataPtr->getFloatValue(argumentIndex, 2) = temp;
    }
    */
};


int Swap::getArity(){
    return Swap::arity;
};
    
Loop::Loop(Data *dataptr): Function(dataptr){};

std::string Loop::getFunctionName(){
    return Loop::functionName;
}

void Loop::execution(){
    int temp; 
};


int Loop::getArity(){
    return Loop::arity;
};
    
