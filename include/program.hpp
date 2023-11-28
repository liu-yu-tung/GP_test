#pragma once
#include "function.hpp"
#include "data.hpp"
#include <vector>
#include <memory>
#include <list>
#include <stdlib.h>

class Program{
    std::unique_ptr<Function> root;
    std::vector<std::unique_ptr<Function>> tree; //store tree in prefix order
    std::shared_ptr<Data> dataPtr;

    /**
     * \brief Choosing a Function for the Function* tree node.
     * \param int Random seed.
     * \return The Choosed Function.
    */
    std::unique_ptr<Function> randomChooseFunction(int);
    std::unique_ptr<Function> randomChooseFunction(int, int);
    /**
     * \brief Called in growTree().
    */
    void grow(std::unique_ptr<Function> &, int, bool);

    /**
     * \brief Base on different method grow the tree.
    */
    void growTree(Const::growMethod);

public:
    Program(Const::growMethod);
    Program(Const::growMethod, Data &);
    void execution();
    void changeData(Data &);
    void show();
};

