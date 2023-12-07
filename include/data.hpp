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
        //Bool, 
        //FunctionInt, 
        //FunctionNone, 
        None,
        NUM_ENTRIES_DATATYPE,
    };
    
    static const int dataLength = 5;
    static const int maximumTreeHeight = 10;
    static int fullTreeNodeNumber = pow(2, maximumTreeHeight)-1;
    
    enum growMethod{
        grow,
        full,
        half_half
    };

    static const growMethod growMethodGlobal = growMethod::full; 

    enum functionSet{
        //IfElse, 
        Head, 
        Nxt,
        Recursive, 
        Swap, 
        //Greater, 
        //Less, 
        //Equal, 
        //Not,
        NUM_ENTRIES
    };

    enum NoneFunc{
        //IfElse_None,
        Recursive_None, 
        Swap_None,
        NUM_ENTRIES_None
    };

    enum IntFunc{
        Head_Int, 
        Nxt_Int, 
        NUM_ENTRIES_Int
    };

    static const int functionSetNumber = static_cast<int>(functionSet::NUM_ENTRIES-1);

    enum Mission{
        Sorting,
        NUM_ENTRIES_MISSION
    };

    static const int trainDataNumber = 100;
    static int randomSeed = 901114;
};

class Data{
public:
    Data();
    Data(Data&);
    int get(int);
    void set(int, int);
    void show();
private:
    std::vector<int> data;
};

