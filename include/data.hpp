#pragma once
#include "function.hpp"
#include <vector>
#include <memory>
#include <iostream>
#include <stdio.h>
#include <cmath>



//defined constants
/**
 * \brief  define namespace Const.
*/
namespace Const{

    enum DataType{
        Int,
        Bool, 
        Function, 
        None
    };
    
    static const int dataLength = 10;
    static const int maximumTreeHeight = 5;
    static int fullTreeNodeNumber = pow(2, maximumTreeHeight)-1;
    
    enum growMethod{
        grow,
        full,
        half_half
    };

    static const growMethod growMethodGlobal = growMethod::full; 

    enum functionSet{
        Recursive, 
        If_else, 
        Swap, 
        Head, 
        Nxt,
        NUM_ENTRIES
    };

    static const int functionSetNumber = static_cast<int>(functionSet::NUM_ENTRIES-1);

    enum Mission{
        Sorting,
        NUM_ENTRIES_MISSION
    };

    static const int trainDataNumber = 100;
    static const int randomSeed = 2023;
};

class Data{
public:
    Data();
    int get(int);
    void set(int, int);
    void show();
private:
    std::vector<int> data;
};

