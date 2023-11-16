#include <iostream>
#include <string>
#include <fstream>
#include "include/data.hpp"
#include "include/function.hpp"
#include "include/program.hpp"
#include "include/fitness.hpp"
#include "include/gp.hpp"
#include "include/generate_train_data.hpp"

int main(int argc, char** argv) {
    freopen( "error.txt", "w", stderr );
    generate_train_data();
    /*
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
    */
    GP gp;
    gp.evolve();
/*
    std::string filename = "./src/train_data.txt";
    std::ifstream read("traindata.txt");
    if(!read.is_open()) std::cout << "didn't open";

    int num;
    read >> num;
    std::cout << num << std::endl;*/
    return 0;
}