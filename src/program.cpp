#include "program.hpp"

Program::Program(Const::growMethod method, Data &data){
    dataPtr = std::make_shared<Data>(data);
    growTree(method);
};

std::unique_ptr<Function> Program::randomChooseFunction(int height, Const::DataType& d){
    srand(Const::randomSeed);
    std::unique_ptr<Function> f;

    int functionNumber;

    switch (d)
    {
    case Const::DataType::None:
        functionNumber = (int)(rand()/Const::NoneFunc::NUM_ENTRIES);
        switch (functionNumber)
        {
        case Const::NoneFunc::IfElse:
            f = std::make_unique<Function>(IfElse(dataPtr));
            break;
        case Const::NoneFunc::Recursive:
            f = std::make_unique<Function>(Recursive(dataPtr));
            break;
        case Const::NoneFunc::Swap:
            f = std::make_unique<Function>(Swap(dataPtr));
            break;
        default:
            break;
        }
        break;
    case Const::DataType::Int:
        functionNumber = (int)(rand()/Const::IntFunc::NUM_ENTRIES);
        switch (functionNumber)
        {
        case Const::NoneFunc::IfElse:
            f = std::make_unique<Function>(IfElse(dataPtr));
            break;
        case Const::NoneFunc::Recursive:
            f = std::make_unique<Function>(Recursive(dataPtr));
            break;
        case Const::NoneFunc::Swap:
            f = std::make_unique<Function>(Swap(dataPtr));
            break;
        default:
            break;
        }
        break;
        break;
    case Const::DataType::Bool:
        functionNumber = (int)(rand()/Const::BoolFunc::NUM_ENTRIES);
        break;
    default:
        break;
    }



        switch (functionNumber)
        {
        case Const::functionSet::Recursive:
            f = std::make_unique<Function>(Recursive(dataPtr));
            break;
        case Const::functionSet::IfElse:
            break;
        case Const::functionSet::Swap:
            f = std::make_unique<Function>(Swap(dataPtr));  
            break;
        case Const::functionSet::Head:
            f = std::make_unique<Function>(Head(dataPtr));
            break;
        case Const::functionSet::Nxt:
            f = std::make_unique<Function>(Nxt(dataPtr));   
            break;
        default:
            break;
        }

    f->setHeight(height);
    return std::move(f);
};

void Program::grow(std::unique_ptr<Function> &f, int height){
    for(Const::DataType &d: f->inType){
        switch (d)
        {
        case Const::DataType::None:
            
            break;
        case Const::DataType::Int:
            break;
        case Const::DataType::Bool:
            break;
        default:
            break;
        }
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

