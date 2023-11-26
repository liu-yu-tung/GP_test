#include "program.hpp"

Program::Program(Const::growMethod method, Data &data){
    dataPtr = std::make_unique<Data>(data);
    growTree(method);
};

std::unique_ptr<Function> Program::randomChooseFunction(int height){
    srand(Const::randomSeed);
    int functionNumber = (int)(rand()/Const::functionSetNumber);
    std::unique_ptr<Function> f;

    switch (functionNumber)
    {
    case Const::functionSet::Loop:
        f = std::make_unique<Function>(Loop());
        break;
    case Const::functionSet::If_else:
        f = std::make_unique<Function>(If_else());
        break;
    case Const::functionSet::Swap:
        f = std::make_unique<Function>(Swap());  
        break;
    case Const::functionSet::Head:
        f = std::make_unique<Function>(Head());
        break;
    case Const::functionSet::Nxt:
        f = std::make_unique<Function>(Nxt());   
        break;
    default:
        break;
    }

    f->setHeight(height);
    return std::move(f);
};

void Program::grow(std::unique_ptr<Function> &f, int height){
    for(std::unique_ptr<Function> child: f->children){
        grow(child, height+1);
    }
    tree.push_back(f);
};


void Program::growTree(Const::growMethod method){
    root = randomChooseFunction(1); // initialize root of Tree
    // Base on different method grow the tree
    if(method==Const::full){
        grow(root, 1);
    }

};

void Program::execution(){
    for(std::unique_ptr<Function> &f:tree){
        f->execution();
    }
};

void Program::changeData(Data& data){
    this->dataPtr = std::make_unique<Data>(data);
};  

