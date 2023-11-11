#pragma once
#include "data.hpp"
#include "function.hpp"
#include <vector>
#include <list>
#include <random>

class Program{
    Function *rootOfTree;
    std::list<Function*> tree;
    Data* dataPtr;
    //to make program get specific function
    Function* createFunction(int, int);
    Function *randomChooseFunction(int);

    void grow(Function *, int);
    void growTree(Const::growMethod);


public:
    Program(Const::growMethod, Data &);
    ~Program();
    void showTree();
    void fillArgument();
};

