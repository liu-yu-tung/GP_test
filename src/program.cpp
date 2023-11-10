#include "../include/program.hpp"

Program::Program(Const::growMethod method){
    growTree(method);
};

Program::~Program(){
    for(Function *f:tree) delete f;
};

Function *Program::randomChooseFunction(int height){
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> distribution(1, Const::functionSetNumber);
    int functionNumber = distribution(gen);
    return createFunction(functionNumber, height);
};

void Program::growTree(Const::growMethod method){
    rootOfTree = randomChooseFunction(1); // initialize root of Tree
    // Base on different method grow the tree
    if(method==Const::full){
        grow(rootOfTree, 1);
    }

    // Fill in the argument of tree
    
    
};

void Program::grow(Function *f, int height){
    if(height==Const::maximumTreeHeight){
        f->addChild(NULL);
        tree.push_back(f);
    }
    else{
        height++;
        Function *left = randomChooseFunction(height);
        Function *right = randomChooseFunction(height);
        f->addChild(left);
        f->addChild(right);
        grow(left, height);
        grow(right, height);
        tree.push_back(f);
    }
};

//to make program get specific function
Function *Program::createFunction(int functionNumber, int height){
    Function* f;
    functionNumber--;
    if(functionNumber==Const::functionSet::Max2){
        f = new Max2;
    }
    else if(functionNumber==Const::functionSet::Swap){
        f = new Swap;
    }
    f->setHeight(height);
    return f;
};

void Program::fillArgument(){
    std::vector<bool> isIndexInit1D = Data::isIndexInit1D;
    std::vector<std::vector<bool>> isIndexInit2D = Data::isIndexInit2D;
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> distributionIndex(0, Data::indexUseNumber);
    std::uniform_int_distribution<int> distributionOutputLength(0, Const::shapeOfBuffer.getLength());
    if(Const::dimensionOfBuffer==2) std::uniform_int_distribution<int> distributionOutputWidth(0, Const::shapeOfBuffer.getWidth());
    
    int arity;

    // For differnet dimension, random choose index of each function by prefix and rechoose if not 
    if(Const::dimensionOfBuffer==1){
        for(Function* f:tree){    
            std::vector<int> index;
            std::vector<int> output;
            for(int i=0; i<f->getArity(); i++) index.push_back(distributionIndex(gen));
            for(int i=0; i<f->getOutputNumber(); i++) {
                int outIndex = distributionOutputLength(gen);
                output.push_back(outIndex);
                isIndexInit1D[outIndex] = true;
            } //isIndexInit1D maintainence?
        }
    }
    else if(Const::dimensionOfBuffer==2){
        
    }


};

void Program::showTree(){
    for(Function* item:tree) std::cout << item->getFunctionName() << ": height " << item->height << std::endl;
};