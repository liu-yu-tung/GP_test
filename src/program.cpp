#include "program.hpp"

Program::Program(Const::growMethod method, Data &data){
    dataPtr = new Data(data);
    growTree(method);
};

Program::~Program(){
    delete dataPtr;
    for(Function *f:tree) delete f;
};

std::unique_ptr<Function> Program::randomChooseFunction(int height){
    srand(Const::randomSeed);
    int functionNumber = (int)(rand()/Const::functionSetNumber);
    std::unique_ptr<Function> f;

    switch (functionNumber)
    {
    case Const::functionSet::Recursive:
        f = std::make_unique<Function>(Recursive());
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
    return std::make_unique(f);
};

void Program::growTree(Const::growMethod method){
    rootOfTree = randomChooseFunction(1); // initialize root of Tree
    // Base on different method grow the tree
    if(method==Const::full){
        grow(rootOfTree, 1);
    }
    // Fill in the argument of tree
    fillArgument();
};

void Program::grow(Function *f, int height){

    /*
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
    }*/
};

void Program::fillArgument(){
    if(dataPtr->getIndexUseNumber()==0) {
        std::cerr << "no Data provide\n";
        return;
    }
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> distributionOutputLength(0, Const::shapeOfBuffer.getLength()-1);
    std::uniform_int_distribution<int> distributionOutputWidth(0, Const::shapeOfBuffer.getWidth()-1);
    
    int arity;
    // For differnet dimension, random choose index of each function by prefix and rechoose if not 

    if(Const::dimensionOfBuffer==1){
        for(Function* f:tree){      
            std::uniform_int_distribution<int> distributionIndex(0, dataPtr->getIndexUseNumber()-1);
            std::vector<int> index;
            std::vector<int> output;
            for(int i=0; i<f->getArity(); i++) index.push_back(dataPtr->indexUse[distributionIndex(gen)]);  //draw from already available index
            for(int i=0; i<f->getOutputNumber(); i++) {
                int outIndex = distributionOutputLength(gen); //draw from all possible index = length of data
                output.push_back(outIndex); 
                dataPtr->setAvailable(outIndex);
            } 
            f->setArgument(index, output);
        }
    }
    else if(Const::dimensionOfBuffer==2){
        for(Function* f:tree){      
            std::uniform_int_distribution<int> distributionIndex(0, dataPtr->getIndexUseNumber()-1);
            std::vector<int> index;
            std::vector<int> output;
            for(int i=0; i<f->getArity(); i++){
                //draw from already available index
                int indexNum = distributionIndex(gen);
                index.push_back(dataPtr->indexUse[indexNum*2]);
                index.push_back(dataPtr->indexUse[indexNum*2+1]);
            }
            for(int i=0; i<f->getOutputNumber(); i++){
                int outIndexL = distributionOutputLength(gen); //draw from all possible index = length of data
                int outIndexW = distributionOutputWidth(gen);
                output.push_back(outIndexL); 
                output.push_back(outIndexW); 
                dataPtr->setAvailable(outIndexL, outIndexW);
            } 
            f->setArgument(index, output);
        }
    }
};
void Program::execution(){
    for(Function *f:tree){
        f->execution();
    }
};

void Program::changeData(Data& data){
    delete dataPtr;
    this->dataPtr = new Data(data);
};  

void Program::showTree(){
    for(Function* item:tree) item->show();
};