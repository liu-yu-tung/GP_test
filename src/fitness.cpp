#include "../include/fitness.hpp"
Fitness::Fitness(Data* d): dataPtr(d), finish(false){};

Sorting::Sorting(Data *d): Fitness(d){};

//ascending
int Sorting::evaluation(){
    int score;
    if(Const::dimensionOfBuffer==1){
        int l = Const::shapeOfBuffer.getLength();
        score = l*(l-1)/2;   
        for(int i=0; i<l; i++){
            for(int j=i+1; j<l; j++){
                if(Const::typeOfBuffer==Int)
                    if(dataPtr->getIntValue(i)>dataPtr->getIntValue(j)) score--;
                if(Const::typeOfBuffer==Float)
                    if(dataPtr->getFloatValue(i)>dataPtr->getFloatValue(j)) score--; 
            }
        } 
        if(score==l*(l-1)/2) finish=true;
    }
    else if(Const::dimensionOfBuffer==2){
        int l = Const::shapeOfBuffer.getLength();
        int w = Const::shapeOfBuffer.getWidth();

        score = (l*w)*((l*w)-1)/2;  
        for(int i=0; i<l; i++){
            for(int j=0; j<w; j++){
                for(int x=j+1; x<w; x++){
                    if(Const::typeOfBuffer==Int)
                        if(dataPtr->getIntValue(i, j)>dataPtr->getIntValue(i, x)) score--;
                    if(Const::typeOfBuffer==Float)
                        if(dataPtr->getFloatValue(i, j)>dataPtr->getFloatValue(i, x)) score--; 
                }
                for(int y=i+1; y<l; y++){
                    for(int z=0; z<w; z++){
                        if(Const::typeOfBuffer==Int)
                            if(dataPtr->getIntValue(i, j)>dataPtr->getIntValue(y, z)) score--;
                        if(Const::typeOfBuffer==Float)
                            if(dataPtr->getFloatValue(i, j)>dataPtr->getFloatValue(y, z)) score--; 
                    }
                }    
            }
        } 
        if(score==(l*w)*((l*w)-1)/2){
            finish=true;      
        }
    }

    return score;
};