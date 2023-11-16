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

    /**
     * \brief To make program get specific function.
     * \param functionNumber Function enum in function set.
     * \param height Set height of the Program.
     * 
     * \return Function pointer.
    */
    Function* createFunction(int, int);

    /**
     * \brief Choosing a Function for the Function* tree node.
     * \param int Random seed.
     * 
     * \return The Choosed Function.
    */
    Function *randomChooseFunction(int);

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

