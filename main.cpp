#include <iostream>
#include "include/data.hpp"
#include "include/function.hpp"
#include "include/program.hpp"
#include "include/fitness.hpp"
#include "include/gp.hpp"

int main(int argc, char** argv) {
    freopen( "error.txt", "w", stderr );
    /*
    GP gp;
    gp.setData(1, 1, 1);
    gp.setData(2, 2, 3);
    gp.generatePopulation();
    gp.show();
    */

    
    std::vector<int> x={1, 1};
    std::vector<int> y={1, 2};
    std::vector<int> z={2, 0};
    std::vector<int> w={2, 1};
    std::vector<int> s={2, 2};
    Data data;
    data.set(x, 5);
    data.set(y, 2);
    data.set(z, 3);
    data.set(w, 4);
    data.set(s, 1);

    
    data.show();
    Sorting C(&data);
    std::cout << C.evaluation() << std::endl;
    data.show();
/*
    Program p(Const::growMethodGlobal, data);
    p.showTree();
    p.execution();

    p.dataPtr->show();
*/

    return 0;
}