#include <iostream>
#include "include/data.hpp"
#include "include/function.hpp"
#include "include/program.hpp"

int main(int argc, char** argv) {
    freopen( "error.txt", "w", stderr );
    //GETINFO();
    
    Data data;
    std::vector<int> x = {1, 1};
    std::vector<int> y = {2, 2};
    data.set(x, 4);
    data.set(y, 5);
    //data.show();
    Data dataA(data);
    //dataA.show();

    Program program(Const::growMethodGlobal, data);
    program.showTree();
    program.execution();
    return 0;
}