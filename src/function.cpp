#include "function.hpp"

const int Function::arity = -1;
const int Function::outputNumber = -1;

<<<<<<< HEAD
/*
=======
const int Leaf::arity = 0;
const int Leaf::outputNumber = 0;
const std::string Leaf::functionName = "Leaf";

>>>>>>> 7ca8db6e4d5283a3d923aa3a2621748d4be32fc6
const int Max2::arity = 2;
const int Max2::outputNumber = 1;
const std::string Max2::functionName = "Max2";
*/
const int Swap::arity = 2;
const int Swap::outputNumber = 0;
const std::string Swap::functionName = "Swap";
const int Loop::arity = 0;
const int Loop::outputNumber = 0;
const std::string Loop::functionName = "Loop";

Function::Function(Data* dataPtr_): dataPtr(dataPtr_){};

/*
void Function::setArgument(std::vector<int> &arguments, std::vector<int> &outputs){
    if(arguments.size()!=getArity()*Const::dimensionOfBuffer){
        std::cerr << getFunctionName() << " should get " << getArity()*Const::dimensionOfBuffer<< " arguments\n";
        return;
    } 
    if(outputs.size()!=getOutputNumber()*Const::dimensionOfBuffer){
        std::cerr << getFunctionName() << " should get " << getOutputNumber()*Const::dimensionOfBuffer<< " arguments\n";
        return;
    } 
    
    argumentIndex = arguments;
    outputIndex = outputs;
};
*/

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

/*
int &Function::getInt(std::vector<int> &index, int order){
    return dataPtr->getIntValue(index, order);
};

float &Function::getFloat(std::vector<int> &index, int order){
    return dataPtr->getFloatValue(index, order);
};

Leaf::Leaf(Data *dataptr): Function(dataptr){};

std::string Leaf::getFunctionName(){
    return Leaf::functionName;
}

int Leaf::getArity(){
    return Leaf::arity;
};

int Leaf::getOutputNumber(){
    return Leaf::outputNumber;
};

void Leaf::execution(){
};

Max2::Max2(Data *dataptr): Function(dataptr){};

std::string Max2::getFunctionName(){
    return Max2::functionName;
}

int Max2::getArity(){
    return Max2::arity;
};

int Max2::getOutputNumber(){
    return Max2::outputNumber;
};

//implementation of max(a, b)
void Max2::execution(){
    int a, b; 
    if(Const::typeOfBuffer==Int){
        a = dataPtr->getIntValue(argumentIndex, 1);
        b = dataPtr->getIntValue(argumentIndex, 2);
    }   
    else if(Const::typeOfBuffer==Float){
        a = dataPtr->getFloatValue(argumentIndex, 1);
        b = dataPtr->getFloatValue(argumentIndex, 2);  
    }
    dataPtr->set(outputIndex, a>b? a:b);
};
*/

Swap::Swap(Data *dataptr): Function(dataptr){};

std::string Swap::getFunctionName(){
    return Swap::functionName;
}

void Swap::execution(){
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
};


int Swap::getArity(){
    return Swap::arity;
};
    
int Swap::getOutputNumber(){
    return Swap::outputNumber;
};


Loop::Loop(Data *dataptr): Function(dataptr){};

std::string Loop::getFunctionName(){
    return Loop::functionName;
}

void Loop::execution(){
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
};


int Loop::getArity(){
    return Loop::arity;
};
    
int Loop::getOutputNumber(){
    return Loop::outputNumber;
};
