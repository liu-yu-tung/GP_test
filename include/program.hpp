#pragma once
#include "data.hpp"
#include "function.hpp"
#include <vector>
#include <list>
#include <random>

class Program{
friend class GP;
    Function *rootOfTree;
    std::vector<Function*> tree;

    //to make program get specific function
    Function* createFunction(int, int);
    Function *randomChooseFunction(int);

    void grow(Function *, int);
    void growTree(Const::growMethod);
    void fillArgument();

public:
    Program(Const::growMethod, Data &);
    ~Program();
    void execution();
    void showTree();
    Data* dataPtr;
};

