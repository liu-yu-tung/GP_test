#include "../include/function.hpp"

const int Function::arity = -1;
const int Function::outputNumber = -1;

const int Max2::arity = 2;
const int Max2::outputNumber = 1;
const std::string Max2::functionName = "Max2";
const int Swap::arity = 2;
const int Swap::outputNumber = 2;
const std::string Swap::functionName = "Swap";

void setArgument(Function &function, std::vector<int> &arguments, std::vector<int> &outputs){
    //check if argument number matches
    if(arguments.size()!=function.getArity()*Const::dimensionOfBuffer){
        std::cerr << function.getFunctionName() << " should get " << function.getArity()*Const::dimensionOfBuffer<< " arguments\n";
        return;
    } 
    if(outputs.size()!=function.getOutputNumber()*Const::dimensionOfBuffer){
        std::cerr << function.getFunctionName() << " should get " << function.getOutputNumber()*Const::dimensionOfBuffer<< " arguments\n";
        return;
    } 
    
    function.argumentIndex = arguments;
    function.outputIndex = outputs;
};

void Function::addChild(Function *child){
    children.push_back(child);
};

void Function::showIO(){
    std::cout << "::::::::::Show Arguments & Outputs::::::::::" << std::endl;
    std::cout << "Arugument index = ";
    for(int index: argumentIndex)
        std::cout << index << " ";
    std::cout << std::endl;
    std::cout << "Outputs index = ";
    for(int index: outputIndex)
        std::cout << index << " ";
    std::cout << std::endl;
    std::cout << "::::::::::::::::::::::::::::::::::::::::::::" << std::endl;
};

void Function::setHeight(int h){
    height = h;
};

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
void Max2::execution(Data &data){
    int a, b;
    std::vector<int> index1(argumentIndex.begin(), argumentIndex.begin()+Const::dimensionOfBuffer);
    std::vector<int> index2(argumentIndex.begin()+Const::dimensionOfBuffer, argumentIndex.begin()+Const::dimensionOfBuffer*2);
    
    if(Const::typeOfBuffer==Int){
        a = data.getIntValue(index1);
        b = data.getIntValue(index2);
    }   
    else if(Const::typeOfBuffer==Float){
        a = data.getFloatValue(index1);
        b = data.getFloatValue(index2);      
    }
    data.set(outputIndex, a>b? a:b);
};

std::string Swap::getFunctionName(){
    return Swap::functionName;
}

void Swap::execution(Data &){
    
};


int Swap::getArity(){

};
    
int Swap::getOutputNumber(){
};