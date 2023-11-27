#include "program.hpp"

Program::Program(Const::growMethod method, Data &data){
    dataPtr = std::make_shared<Data>(data);
    growTree(method);
};

std::unique_ptr<Function> Program::randomChooseFunction(int height){
    srand(Const::randomSeed);
    std::unique_ptr<Function> f;
    int functionNumber = (int)(rand()/Const::functionSetNumber);  
    switch (functionNumber)
    {
    case Const::functionSet::Head:
        f = std::make_unique<Head>(dataPtr);
        break;
    case Const::functionSet::Nxt:
        f = std::make_unique<Nxt>(dataPtr);
        break;
    case Const::functionSet::IfElse:
        f = std::make_unique<IfElse>(dataPtr);
        break;
    case Const::functionSet::Recursive:
        f = std::make_unique<Recursive>(dataPtr);
        break;
    case Const::functionSet::Swap:
        f = std::make_unique<Swap>(dataPtr);
        break;
    case Const::functionSet::Greater:
        f = std::make_unique<Greater>(dataPtr);
        break;
    case Const::functionSet::Less:
        f = std::make_unique<Less>(dataPtr);
        break;
    case Const::functionSet::Equal:
        f = std::make_unique<Equal>(dataPtr);
        break;
    case Const::functionSet::Not:
        f = std::make_unique<Not>(dataPtr);
        break;                
    default:
        break;
    }

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
        case Const::IntFunc::Head:
            f = std::make_unique<Function>(Head(dataPtr));
            break;
        case Const::IntFunc::Nxt:
            f = std::make_unique<Function>(Nxt(dataPtr));
            break;
        default:
            break;
        }
        break;
    case Const::DataType::Bool:
        functionNumber = (int)(rand()/Const::BoolFunc::NUM_ENTRIES);
        switch (functionNumber)
        {
        case Const::BoolFunc::Greater:
            f = std::make_unique<Function>(Greater(dataPtr));
            break;
        case Const::BoolFunc::Less:
            f = std::make_unique<Function>(Less(dataPtr));
            break;
        case Const::BoolFunc::Equal:
            f = std::make_unique<Function>(Equal(dataPtr));
            break;
        case Const::BoolFunc::Not:
            f = std::make_unique<Function>(Not(dataPtr));
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    f->setHeight(height);
    return std::move(f);
};

void Program::grow(std::unique_ptr<Function> &f, int height, bool inRecursive){
    f->inRecursive = inRecursive;
    if(height==Const::maximumTreeHeight) return;
    for(Const::DataType &d: f->inType){
        std::unique_ptr<Function> child = randomChooseFunction(height+1, d);
        if(child->getFunctionName()=="Recursive" || inRecursive) grow(child, height+1, true);
        else grow(child, height+1, false);
        f->children.push_back(child);
    }
    tree.push_back(f);
};


void Program::growTree(Const::growMethod method){
    root = randomChooseFunction(1); // initialize root of Tree
    // Base on different method grow the tree
    if(method==Const::full){
        grow(root, 1, false);
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

void Program::show(){
    for(std::unique_ptr<Function> &f:tree){
        std::cout << "Function Name: " << f->getFunctionName() << std::endl;
    }
};

