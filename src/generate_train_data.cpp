#include "generate_train_data.hpp"

/*
void sorting();

Const::Mission mission = Const::Sorting;
int totalNumber = Const::trainDataNumber; 
int dimension = Const::dimensionOfBuffer;
Shape shape = Const::shapeOfBuffer;
DataType type = Const::typeOfBuffer;

std::ofstream outputFile;

void generate_train_data(){
    std::string filename = "../src/train_data.txt";
    outputFile.open(filename);

    if (!outputFile.is_open()) {
        std::cout << "Cannot open: " << filename << std::endl;
    }    
    
    switch(mission){
        case Const::Mission::Sorting:
            for(int i=0; i<totalNumber; i++) sorting();
            break;
        default:
            break;
    }

    
    outputFile.close();
};

void sorting(){
    std::random_device rd;
    std::mt19937 gen(rd());
    if(type==Int){
        std::vector<int> buffer;
        std::uniform_int_distribution<int> distribution(-100, 100);
        if(dimension==1){
            for(int i=0; i<shape.getLength(); i++){
                int randomNumber = distribution(gen);
                buffer.push_back(randomNumber);
                outputFile << randomNumber << " ";
            }
            outputFile << std::endl;
        }
        else if(dimension==2){
            for(int i=0; i<shape.getLength(); i++){
                for(int j=0; j<shape.getWidth(); j++){
                    int randomNumber = distribution(gen);
                    buffer.push_back(randomNumber);
                    outputFile << randomNumber << " ";
                }
            }  
            outputFile << std::endl;     
        }
    }
    else if(type==Float){
        std::vector<float> buffer;
        std::uniform_real_distribution<float> distribution(-100.0, 100.0);
        if(dimension==1){
            for(int i=0; i<shape.getLength(); i++){
                float randomNumber = distribution(gen);
                buffer.push_back(randomNumber);
                outputFile << randomNumber << " ";
            }
            outputFile << std::endl;
        }
        else if(dimension==2){
            for(int i=0; i<shape.getLength(); i++){
                for(int j=0; j<shape.getWidth(); j++){
                    float randomNumber = distribution(gen);
                    buffer.push_back(randomNumber);
                    outputFile << randomNumber << " ";
                }
            }    
            outputFile << std::endl;  
        }
    }
};*/