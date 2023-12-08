#pragma once
#include "function.hpp"
#include "data.hpp"
#include <string>
#include <vector>
#include <memory>
#include <list>
#include <stdlib.h>

class Program{
    std::shared_ptr<Function> root;
    std::vector<std::shared_ptr<Function>> tree; //store tree in prefix order
    std::shared_ptr<Data> dataPtr;

    /**
     * \brief Choosing a Function for the Function* tree node.
     * \param int Random seed.
     * \return The Choosed Function.
    */
    std::shared_ptr<Function> randomChooseFunction(int);
    std::shared_ptr<Function> randomChooseFunction(int, int);
    std::shared_ptr<Function> randomChooseNonRecursiveFunction(int, int);
    /**
     * \brief Called in growTree().
    */
    void grow(std::shared_ptr<Function> &, int, bool);
    void growWithoutRecursive(std::shared_ptr<Function> &, int, bool);

    /**
     * \brief Base on different method grow the tree.
    */
    void growTree(Const::growMethod);

public:
    Program(Const::growMethod);
    Program(Const::growMethod, Data &);
    ~Program();
    void execution();
    void changeData(Data &);
    void show();
    void showData();
};

