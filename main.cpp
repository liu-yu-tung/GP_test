#include <iostream>
#include <string>
#include <fstream>
#include "data.hpp"
#include "function.hpp"
#include "program.hpp"
//#include "fitness.hpp"
//#include "gp.hpp"
//#include "generate_train_data.hpp"
/**
 * Doxygen comments go here.
 *
 * The extra asterisks to the left are not required, but they are nice to have
 * visually.
 */

/**
 * \brief The main function.
 *
 * This function run the gp.
 * 
 * \param argc The number of arguments.
 * \param argv The vector of arguments.
 * \return The exec result of main function.
 */
void unbuffered_io() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
}

int main(int argc, char** argv) {
    srand(Const::randomSeed);
    unbuffered_io();
    //freopen( "error.txt", "w", stderr);
    Data data;
    data.set(0, 2);
    data.set(1, 3);
    data.set(2, 4);
    data.set(3, 5);
    data.set(4, 6);
    data.show();
    fprintf(stderr, "here0\n");
    Program P(Const::growMethod::full, data);
    fprintf(stderr, "here1\n");
    P.changeData(data);
    P.show();
    P.execution();
    data.show();
    /*  
    std::string filename = "./src/train_data.txt";
    std::ifstream read("traindata.txt");
    if(!read.is_open()) std::cout << "didn't open";

    int num;
    read >> num;
    std::cout << num << std::endl;
    */
    return 0;
}