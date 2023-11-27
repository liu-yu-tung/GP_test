#include "function.hpp"

const int Function::arity = -1;

// IfElse
const int IfElse::arity = 3;
const std::string IfElse::functionName = "IfElse";
const std::vector<Const::DataType> IfElse::inType = {Const::DataType::Bool, Const::DataType::Function, Const::DataType::Function};
const Const::DataType IfElse::outType = Const::DataType::None;

// Recursive
const int Recursive::arity = 1;
const std::string Recursive::functionName = "Recursive";
const std::vector<Const::DataType> Recursive::inType = {Const::DataType::Function};
const Const::DataType Recursive::outType = Const::DataType::None;

// Swap
const int Swap::arity = 2;
const std::string Swap::functionName = "Swap";
const std::vector<Const::DataType> Swap::inType = {Const::DataType::Int, Const::DataType::Int};
const Const::DataType Swap::outType = Const::DataType::None;

// Nxt
const int Nxt::arity = 0;
const std::string Nxt::functionName = "Nxt";
const std::vector<Const::DataType> Nxt::inType = {Const::DataType::None};
const Const::DataType Nxt::outType = Const::DataType::Int;

// Head
const int Head::arity = 0;
const std::string Head::functionName = "Head";
const std::vector<Const::DataType> Head::inType = {Const::DataType::None};
const Const::DataType Head::outType = Const::DataType::Int;

// GetDataByIndex
const int GetDataByIndex::arity = 1;
const std::string GetDataByIndex::functionName = "GetDataByIndex";
const std::vector<Const::DataType> GetDataByIndex::inType = {Const::DataType::Int};
const Const::DataType GetDataByIndex::outType = Const::DataType::Int;

// Assign
const int Assign::arity = 2;
const std::string Assign::functionName = "Assign";
const std::vector<Const::DataType> Assign::inType = {Const::DataType::Int, Const::DataType::Int};
const Const::DataType Assign::outType = Const::DataType::Int;

// BoolEqual
const int BoolEqual::arity = 2;
const std::string BoolEqual::functionName = "BoolEqual";
const std::vector<Const::DataType> BoolEqual::inType = {Const::DataType::Int, Const::DataType::Int};
const Const::DataType BoolEqual::outType = Const::DataType::Bool;

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
    int params[2] = {children[0]->intResult + listBegin, children[1]->intResult + listBegin};
    int tmp1 = (dataPtr->get(params[0]));
    int tmp2 = (dataPtr->get(params[1]));
    dataPtr->set(params[0], tmp2);
    dataPtr->set(params[1], tmp1);
};

int Swap::getArity(){
    return Swap::arity;
};

    
IfElse::IfElse(Data *dataptr): Function(dataptr){};

std::string IfElse::getFunctionName(){
    return IfElse::functionName;
}

void IfElse::execution(){
    /*
    Function* f = children[0];
    Function* g = children[1];
    f->execution();
    */
};

int IfElse::getArity(){
    return IfElse::arity;
};
    

Recursive::Recursive(Data *dataptr): Function(dataptr){};

std::string Recursive::getFunctionName(){
    return Recursive::functionName;
}

void Recursive::execution(){
};

int Recursive::getArity(){
    return Recursive::arity;
};
    
Nxt::Nxt(Data *dataptr): Function(dataptr){};

std::string Nxt::getFunctionName(){
    return Nxt::functionName;
}

void Nxt::execution(){
    intResult = listBegin + 1;
};

int Nxt::getArity(){
    return Nxt::arity;
};
    

Head::Head(Data *dataptr): Function(dataptr){};

std::string Head::getFunctionName(){
    return Head::functionName;
}

void Head::execution(){
    intResult = listBegin;
};

int Head::getArity(){
    return Head::arity;
};
    
GetDataByIndex::GetDataByIndex(Data *dataptr): Function(dataptr){};

std::string GetDataByIndex::getFunctionName(){
    return GetDataByIndex::functionName;
}

void GetDataByIndex::execution(){
};

int GetDataByIndex::getArity(){
    return GetDataByIndex::arity;
};
    
Assign::Assign(Data *dataptr): Function(dataptr){};

std::string Assign::getFunctionName(){
    return Assign::functionName;
}

void Assign::execution(){

};

int Assign::getArity(){
    return Assign::arity;
};
    
BoolEqual::BoolEqual(Data *dataptr): Function(dataptr){};

std::string BoolEqual::getFunctionName(){
    return BoolEqual::functionName;
}

void BoolEqual::execution(){
    int params[2] = {children[0]->intResult + listBegin, children[1]->intResult + listBegin};
    if (params[0] == params[1]) {
        boolResult = true;
    } else {
        boolResult = false;
    }
};

int BoolEqual::getArity(){
    return BoolEqual::arity;
};
    