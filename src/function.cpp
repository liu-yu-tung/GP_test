#include "function.hpp"

const int Function::arity = -1;

// IfElse
const int IfElse::arity = 3;
const std::string IfElse::functionName = "IfElse";
const std::vector<int> IfElse::inType = {Const::DataType::Bool, Const::DataType::Function, Const::DataType::Function};
const int IfElse::outType = Const::DataType::None;
const int IfElse::functionEnum = Const::functionSet::IfElse;

// Recursive
const int Recursive::arity = 1;
const std::string Recursive::functionName = "Recursive";
const std::vector<int> Recursive::inType = {Const::DataType::Function};
const int Recursive::outType = Const::DataType::None;
const int Recursive::functionEnum = Const::functionSet::Recursive;

// Swap
const int Swap::arity = 2;
const std::string Swap::functionName = "Swap";
const std::vector<int> Swap::inType = {Const::DataType::Int, Const::DataType::Int};
const int Swap::outType = Const::DataType::None;
const int Swap::functionEnum = Const::functionSet::Swap;

// Nxt
const int Nxt::arity = 0;
const std::string Nxt::functionName = "Nxt";
const std::vector<int> Nxt::inType = {Const::DataType::None};
const int Nxt::outType = Const::DataType::Int;
const int Nxt::functionEnum = Const::functionSet::Nxt;

// Head
const int Head::arity = 0;
const std::string Head::functionName = "Head";
const std::vector<int> Head::inType = {Const::DataType::None};
const int Head::outType = Const::DataType::Int;
const int Head::functionEnum = Const::functionSet::Head;

// GetDataByIndex
const int GetDataByIndex::arity = 1;
const std::string GetDataByIndex::functionName = "GetDataByIndex";
const std::vector<int> GetDataByIndex::inType = {Const::DataType::Int};
const int GetDataByIndex::outType = Const::DataType::Int;

// Assign
const int Assign::arity = 2;
const std::string Assign::functionName = "Assign";
const std::vector<int> Assign::inType = {Const::DataType::Int, Const::DataType::Int};
const int Assign::outType = Const::DataType::Int;

// BoolEqual
const int BoolEqual::arity = 2;
const std::string BoolEqual::functionName = "BoolEqual";
const std::vector<int> BoolEqual::inType = {Const::DataType::Int, Const::DataType::Int};
const int BoolEqual::outType = Const::DataType::Bool;

Function::Function(std::shared_ptr<Data> dataPtr_): dataPtr(dataPtr_){};
void Function::addChild(std::unique_ptr<Function> child){
    children.push_back(std::move(child));
};

Function::~Function() {};

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


Swap::Swap(std::shared_ptr<Data> dataptr): Function(dataptr){};

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

int Swap::getFunctionEnum(){
    return functionEnum;
};
    
IfElse::IfElse(std::shared_ptr<Data> dataptr): Function(dataptr){};

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

int IfElse::getFunctionEnum(){
    return functionEnum;
};

Recursive::Recursive(std::shared_ptr<Data> dataptr): Function(dataptr){};

std::string Recursive::getFunctionName(){
    return Recursive::functionName;
}

void Recursive::execution(){
};

int Recursive::getArity(){
    return Recursive::arity;
};

int Recursive::getFunctionEnum(){
    return functionEnum;
};
    
Nxt::Nxt(std::shared_ptr<Data> dataptr): Function(dataptr){};

std::string Nxt::getFunctionName(){
    return Nxt::functionName;
}

void Nxt::execution(){
    intResult = listBegin + 1;
};

int Nxt::getArity(){
    return Nxt::arity;
};

int Nxt::getFunctionEnum(){
    return functionEnum;
};
    
Head::Head(std::shared_ptr<Data> dataptr): Function(dataptr){};

std::string Head::getFunctionName(){
    return Head::functionName;
}

void Head::execution(){
    intResult = listBegin;
};

int Head::getArity(){
    return Head::arity;
};
    
int Head::getFunctionEnum(){
    return functionEnum;
};

GetDataByIndex::GetDataByIndex(std::shared_ptr<Data> dataptr): Function(dataptr){};

std::string GetDataByIndex::getFunctionName(){
    return GetDataByIndex::functionName;
}

void GetDataByIndex::execution(){
};

int GetDataByIndex::getArity(){
    return GetDataByIndex::arity;
};
    
Assign::Assign(std::shared_ptr<Data> dataptr): Function(dataptr){};

std::string Assign::getFunctionName(){
    return Assign::functionName;
}

void Assign::execution(){

};

int Assign::getArity(){
    return Assign::arity;
};
    
BoolEqual::BoolEqual(std::shared_ptr<Data> dataptr): Function(dataptr){};

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
    