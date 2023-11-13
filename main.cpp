#include <iostream>
#include "include/data.hpp"
#include "include/function.hpp"
#include "include/program.hpp"
#include "include/fitness.hpp"
#include "include/gp.hpp"

int main(int argc, char** argv) {
    freopen( "error.txt", "w", stderr );
    
    GP gp;
    gp.setData(1, 1, 5);
    gp.setData(1, 2, 2);
    gp.setData(2, 0, 3);
    gp.setData(2, 1, 4);
    gp.setData(2, 2, 1);
    gp.showData();
    gp.initialize();
    //gp.show();
    gp.run();
    
    return 0;
}