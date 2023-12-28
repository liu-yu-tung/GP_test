#include "function.hpp"

const int Function::arity = -1;

// IfElse
const int IfElse::arity = 3;
const std::string IfElse::functionName = "IfElse";
const std::vector<int> IfElse::inType = {Const::DataType::Bool, Const::DataType::None, Const::DataType::None};
const int IfElse::outType = Const::DataType::None;
const int IfElse::functionEnum = Const::functionSet::IfElse;


// Recursive
const int Recursive::arity = 1;
const std::string Recursive::functionName = "Recursive";
const std::vector<int> Recursive::inType = {Const::DataType::None};
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

// // GetDataByIndex
// const int GetDataByIndex::arity = 1;
// const std::string GetDataByIndex::functionName = "GetDataByIndex";
// const std::vector<int> GetDataByIndex::inType = {Const::DataType::Int};
// const int GetDataByIndex::outType = Const::DataType::Int;
// 
// // Assign
// const int Assign::arity = 2;
// const std::string Assign::functionName = "Assign";
// const std::vector<int> Assign::inType = {Const::DataType::Int, Const::DataType::Int};
// const int Assign::outType = Const::DataType::Int;
// 
// BoolEqual
const int Equal::arity = 2;
const std::string Equal::functionName = "Equal";
const std::vector<int> Equal::inType = {Const::DataType::Int, Const::DataType::Int};
const int Equal::outType = Const::DataType::Bool;

/*
// Less
const int Less::arity = 2;
const std::string Less::functionName = "Less";
const std::vector<int> Less::inType = {Const::DataType::Int, Const::DataType::Int};
const int Less::outType = Const::DataType::Bool;
*/

// Greater
/*
const int Greater::arity = 2;
const std::string Greater::functionName = "Greater";
const std::vector<int> Greater::inType = {Const::DataType::Int, Const::DataType::Int};
const int Greater::outType = Const::DataType::Bool;
*/

Function::Function(std::shared_ptr<Data> dataPtr_): dataPtr{dataPtr_}{};
void Function::addChild(std::shared_ptr<Function> child){
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
    fprintf(stderr, "%s\n", functionName.c_str());
    if (inRecursive) {
        for(auto &c : children) {
            if (c != NULL && children.size()) {
                c->execution();
            }
        }
    }
    
    for (auto c : children) {
        if (c != NULL && children.size()) {
            listBegin = listBegin > c->listBegin ? listBegin : c->listBegin;
        }
        listBegin %= Const::dataLength;
    }    
    int params[2] = {0, 0};
    if (children.size() == 2) {
        if (children[0] != NULL) {
            params[0] = { children[0]->intResult + listBegin};
        } 
        if (children[1] != NULL) {
                params[1] = params[0]+1;
        }
    } else {
        params[0] = listBegin;
        params[1] = listBegin + 1;
    }
    if (params[0] == params[1]) {
        params[1] = (params[0]+1)%Const::dataLength;
    }
    params[0]%=Const::dataLength;
    params[1]%=Const::dataLength;
    fprintf(stderr, "params: %d, %d\n", params[0], params[1]);
    int tmp1 = (dataPtr->get(params[0]));
    int tmp2 = (dataPtr->get(params[1]));
    dataPtr->set(params[0], tmp2);
    dataPtr->set(params[1], tmp1);
    listBegin++;
    dataPtr->show();
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
    bool state = children[0]->boolResult;
    std::shared_ptr<Function> f = children[1];
    std::shared_ptr<Function> g = children[2];
    if (state) {
        f->execution();
    } else {
        g->execution();
    }
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
    fprintf(stderr, "%s\n", functionName.c_str());
    bool no_child = true;
    while(listBegin<Const::dataLength-1 && children.size() && children[0] != NULL) {
        for(auto &c : children) {
            if (c != NULL) {
                fprintf(stderr, "c != NULL\n");
                no_child = false;
                c->execution();
                listBegin = c->listBegin;
            } 
        }
        if (no_child) {
            fprintf(stderr, "Recursive is empty\n");
            listBegin = Const::dataLength - 1;
            dataPtr->show();
            return ;
        }
    }
    if (no_child) {
        fprintf(stderr, "Recursive is empty\n");
        listBegin = Const::dataLength - 1;
        dataPtr->show();
        return ;
    }

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
    fprintf(stderr, "%s\n", functionName.c_str());
    if (inRecursive) {
        for(auto &c : children) {
            if (c != NULL) {
                c->execution();
            }
        }
    }
    for (auto c : children) {
        if (c != NULL) {
            listBegin = listBegin > c->listBegin ? listBegin : c->listBegin;
        }
    }
    intResult = (listBegin + 1)%Const::dataLength;
    listBegin++;
    dataPtr->show();
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
    fprintf(stderr, "%s\n", functionName.c_str());
    if (inRecursive) {
        for(auto &c : children) {
            if (c != NULL) {
                c->execution();
            }
        }
    }
    for (auto c : children) {
        if (c != NULL) {
            listBegin = listBegin > c->listBegin ? listBegin : c->listBegin;
        }
    }
    intResult = listBegin;
    listBegin++;
    dataPtr->show();
};

int Head::getArity(){
    return Head::arity;
};
    
int Head::getFunctionEnum(){
    return functionEnum;
};

// GetDataByIndex::GetDataByIndex(std::shared_ptr<Data> dataptr): Function(dataptr){};
// 
// std::string GetDataByIndex::getFunctionName(){
//     return GetDataByIndex::functionName;
// }
// 
// void GetDataByIndex::execution(){
//     fprintf(stderr, "%s\n", functionName.c_str());
//     dataPtr->show();
// };
// 
// int GetDataByIndex::getArity(){
//     return GetDataByIndex::arity;
// };
//     
// Assign::Assign(std::shared_ptr<Data> dataptr): Function(dataptr){};
// 
// std::string Assign::getFunctionName(){
//     return Assign::functionName;
// }
// 
// void Assign::execution(){
//     fprintf(stderr, "%s\n", functionName.c_str());
//     dataPtr->show();
// 
// };
// 
// int Assign::getArity(){
//     return Assign::arity;
// };
//     
Equal::Equal(std::shared_ptr<Data> dataptr): Function(dataptr){};

std::string Equal::getFunctionName(){
    return Equal::functionName;
}

void Equal::execution(){
    int params[2] = {children[0]->intResult + listBegin, children[1]->intResult + listBegin};
    if (params[0] == params[1]) {
        boolResult = true;
    } else {
        boolResult = false;
    }
};

int Equal::getArity(){
   return Equal::arity;
};

int Equal::getFunctionEnum(){
    return functionEnum;
};
/*
Less::Less(std::shared_ptr<Data> dataptr): Function(dataptr){};

std::string Less::getFunctionName(){
    return Less::functionName;
}

void Less::execution(){
    int params[2] = {children[0]->intResult + listBegin, children[1]->intResult + listBegin};
    if (params[0] < params[1]) {
        boolResult = true;
    } else {
        boolResult = false;
    }
};

int Less::getArity(){
    return Less::arity;
};
*/
/*    
Greater::Greater(std::shared_ptr<Data> dataptr): Function(dataptr){};

std::string Greater::getFunctionName(){
    return Greater::functionName;
}

void Greater::execution(){
    int params[2] = {children[0]->intResult + listBegin, children[1]->intResult + listBegin};
    if (params[0] > params[1]) {
        boolResult = true;
    } else {
        boolResult = false;
    }
};

int Greater::getArity(){
    return Greater::arity;
};
*/    