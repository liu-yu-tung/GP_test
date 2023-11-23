#pragma once
#include "function.hpp"
#include "data.hpp"
#include <vector>
#include <memory>
#include <list>
#include <stdlib.h>

class Program{
    Function *rootOfTree;
    std::vector<std::unique_ptr<Function>> tree;

    /**
     * \brief Choosing a Function for the Function* tree node.
     * \param int Random seed.
     * 
     * \return The Choosed Function.
    */
    std::unique_ptr<Function> randomChooseFunction(int);

    /**
     * \brief Called in growTree().
    */
    void grow(Function *, int);

    /**
     * \brief Base on different method grow the tree.
    */
    void growTree(Const::growMethod);

    /**
     * For differnet dimension, random choose index of each function by prefix and rechoose if not 
    */
    void fillArgument();

public:
    Program(Const::growMethod, Data &);
    ~Program();
    void execution();
    void showTree();
    void changeData(Data &);
    Data* dataPtr;
};

