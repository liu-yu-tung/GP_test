#include "program.hpp"

Program::Program(Const::growMethod method){
    growTree(method);
};

Program::Program(Const::growMethod method, Data &data){
    dataPtr = std::make_shared<Data>(data);
    growTree(method);
};

Program::~Program() {};

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
 /*   case Const::functionSet::Greater:
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
        break;    */            
    default:
        break;
    }
    return std::move(f);
};

std::unique_ptr<Function> Program::randomChooseFunction(int height, int d){
    srand(Const::randomSeed);
    std::unique_ptr<Function> f;

    int functionNumber;

    switch (d)
    {
    case Const::DataType::None:
        functionNumber = (int)(rand()/Const::NoneFunc::NUM_ENTRIES_None);
        switch (functionNumber)
        {
        case Const::NoneFunc::IfElse_None:
            f = std::make_unique<IfElse>(dataPtr);
            break;
        case Const::NoneFunc::Recursive_None:
            f = std::make_unique<Recursive>(dataPtr);
            break;
        case Const::NoneFunc::Swap_None:
            f = std::make_unique<Swap>(dataPtr);
            break;
        default:
            break;
        }
        break;
    case Const::DataType::Int:
        functionNumber = (int)(rand()/Const::IntFunc::NUM_ENTRIES_Int);
        switch (functionNumber)
        {
        case Const::IntFunc::Head_Int:
            f = std::make_unique<Head>(dataPtr);
            break;
        case Const::IntFunc::Nxt_Int:
            f = std::make_unique<Nxt>(dataPtr);
            break;
        default:
            break;
        }
        break;
  /*  case Const::DataType::Bool:
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
        break;*/
    default:
        break;
    }
    f->setHeight(height);
    return std::move(f);
};

void Program::grow(std::unique_ptr<Function> &f, int height, bool inRecursive){
    f->inRecursive = inRecursive;
    if(height==Const::maximumTreeHeight) return;

    std::unique_ptr<std::vector<int>> inType;
    switch (f->getFunctionEnum())
    {
    case Const::functionSet::IfElse:
        inType = std::make_unique<std::vector<int>>(IfElse::inType);
        break;
    case Const::functionSet::Recursive:
        inType = std::make_unique<std::vector<int>>(Recursive::inType);
        break;
    case Const::functionSet::Swap:
        inType = std::make_unique<std::vector<int>>(Swap::inType);
        break;
    case Const::functionSet::Head:
        inType = std::make_unique<std::vector<int>>(Head::inType);
        break;
    case Const::functionSet::Nxt:
        inType = std::make_unique<std::vector<int>>(Nxt::inType);
        break;
    default:
        break;
    }
    for(int d: *inType){
        std::unique_ptr<Function> child = randomChooseFunction(height+1, d);
        if(child->getFunctionName()=="Recursive" || inRecursive) grow(child, height+1, true);
        else grow(child, height+1, false);
        f->children.push_back(std::move(child));
    }
    tree.push_back(std::move(f));
};


void Program::growTree(Const::growMethod method){
    root = randomChooseFunction(1); // initialize root of Tree
    // Base on different method grow the tree
    if(method==Const::full){
        grow(root, 1, false);
    }
};

void Program::execution(){
    for(const auto &f:tree){
        f->execution();
    }
};

void Program::changeData(Data& data){
    std::unique_ptr<Data> ptr = std::make_unique<Data>(data);
    this->dataPtr = std::move(ptr);
};  

void Program::show(){
    for(const auto &f:tree){
        std::cout << "Function Name: " << f->getFunctionName() << std::endl;
    }
};

