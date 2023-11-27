#include "gp.hpp"
const Const::Mission GP::mission = Const::Mission::Sorting;
const int GP::totalPopulation = 100;
const int GP::maximumGeneration = 30;

std::unique_ptr<Data> GP::data;

GP::GP(){
    largestFitness = 0;
    data = std::make_unique<Data>();
    prefixReference.resize(Const::fullTreeNodeNumber);
    infixReference.resize(Const::fullTreeNodeNumber);
    int count = 0;
    generatePrefix(0, count);
};

GP::~GP(){
    for(Program* program:population) delete program;
};
/*
void GP::setData(int x, int i){
    if(Const::dimensionOfBuffer!=1 || Const::typeOfBuffer!=Int) std::cerr << "Cannot set not one dimensional or not int data\n";
    else{
        std::vector<int> index;
        index.push_back(x);
        data->set(index, i);
    }
};

void GP::setData(int x, int y, int i){
    if(Const::dimensionOfBuffer!=2 || Const::typeOfBuffer!=Int) std::cerr << "Cannot set not two dimensional or not int data\n";
    else{
        std::vector<int> index;
        index.push_back(x);
        index.push_back(y);
        data->set(index, i);
    }
};

void GP::setData(int x, float f){
    if(Const::dimensionOfBuffer!=1 || Const::typeOfBuffer!=Float) std::cerr << "Cannot set not one dimensional or not float data\n";
    else{
        std::vector<int> index;
        index.push_back(x);
        data->set(index, f);
    }
};

void GP::setData(int x, int y, float f){
    if(Const::dimensionOfBuffer!=2 || Const::typeOfBuffer!=Float) std::cerr << "Cannot set not two dimensional or not float data\n";
    else{
        std::vector<int> index;
        index.push_back(x);
        index.push_back(y);
        data->set(index, f);
    }
};

void GP::generatePopulation(){
    if(Const::growMethodGlobal!=Const::growMethod::half_half){
        for(int i=0; i<totalPopulation; i++){
            Program* programPtr = new Program(Const::growMethodGlobal, *data);
            population.push_back(programPtr);
        }
    }
    else if(Const::growMethodGlobal==Const::growMethod::half_half){}
    std::cout << "Generate Population Done\n";
};

void GP::evaluation(){

    finish=false;
    totalFitness=0;
    totalInverseFitness=0;
    fitnessAccumulation.resize(0);
    fitnessInverseAccumulation.resize(0);

    int fit;
    int index=0;
    for(Program* program:population) {
        program->execution();
        if(mission==Const::Mission::Sorting){
            Sorting sort(program->dataPtr);
            fit=sort.evaluation();
            if(sort.finish) finish=true;
            fitness.push_back(fit);
            totalFitness+=fit;
        }
        
        if(fit>largestFitness){
            finalProgram = program;
            largestFitness = fit;
        }
        fitnessAccumulation.push_back(totalFitness);
        fitnessInverseAccumulation.push_back(1/totalFitness);
        index++;
    }
    std::string missionName;
    if(mission==Const::Mission::Sorting) missionName = "Sorting";
    //std::cout << "Evalutaion Done: Mission type " << missionName << "\n";
};

int GP::weightedSelect(){
    if (fitnessAccumulation.empty()) {
        std::cerr << "Error: Empty vector\n";
        return -1;  
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, totalFitness);
    int randomNumber = distribution(gen);

    for (int i=0; i<totalPopulation; i++){
        if (randomNumber <= fitnessAccumulation[i])
            return i;
    }
    std::cerr << "Error: Unable to make a choice\n";
    return -1;
}

void GP::show(){
    for(Program* program:population) program->showTree();
};

void GP::showData(){
    std::cout << "Your gp's data is set as shown below:\n";
    data->show();
};

void GP::deleteRandom(){
    if (fitnessInverseAccumulation.empty()) {
        std::cerr << "Error: Empty vector\n";  
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distribution(0, totalInverseFitness);
    float randomNumber = distribution(gen);

    int index;
    for (int i=0; i<totalPopulation; i++){
        if (randomNumber < fitnessInverseAccumulation[i]){
            index = i;
            break;
        }
    }
    population.erase(population.begin()+index, population.begin()+index+1);
};

void GP::swap(int index1, int begin1, int end1, int index2, int begin2, int end2){
    std::vector<Function*> temp;
    std::vector<Function*> &f1=population[index1]->tree;
    std::vector<Function*> &f2=population[index2]->tree;
    std::swap_ranges(f1.begin()+begin1, f1.begin()+end1+1, f2.begin()+begin2);
};

void GP::generatePrefix(int num, int &count){
    if((num+1)*2 <= Const::fullTreeNodeNumber){
        generatePrefix((num+1)*2-1, count);
        generatePrefix((num+1)*2, count);
    }
    prefixReference[num] = count;
    infixReference[count] = num;
    count++;
};

void GP::reproduce(int index1, int index2){
    if(Const::growMethodGlobal==Const::growMethod::full){
        std::random_device rd; 
        std::mt19937 gen(rd()); 
        std::uniform_int_distribution<int> randomNode(1, Const::fullTreeNodeNumber);
        int node = randomNode(gen);
        int begin = node;
        int end = prefixReference[node-1];

        while(2*begin<=Const::fullTreeNodeNumber) begin *= 2;
        begin=prefixReference[begin-1];
        //std::cout << begin << " " << end << "\n";
        swap(index1, begin, end, index2, begin, end);
    }
};

void GP::crossover(){
    int program1 = weightedSelect();
    int program2 = weightedSelect();
    //std::cout << "Program 1 index: " << program1 << std::endl;
    //std::cout << "Program 2 index: " << program2 << std::endl;
    reproduce(program1, program2);
};

void GP::run(){
    for(int i=1; i<=maximumGeneration; i++){
        if(population.size()==0){
            std::cout << "No program" << std::endl;
            break;
        }
        evaluation();
        
        if(finish){      
            std::cout << "Terminate Early! This is the final Program:\n";
            break;
        }

        for(int i=0; i<20; i++) 
            crossover();
        
        //std::cout << population.size() << " program remained" <<"\n";
    }
    //std::cout << "This is the final Program:\n";
    //finalProgram->showTree();
    //std::cout << "Fitness: " << largestFitness << "\n";
};

void GP::evolve(){
    bool isGenerated = false;
    fitnessAverage.resize(totalPopulation, 0);
    //counter for showing program progress 
    int loopCounter = 0;
    int counter = 0;
 
    //input train data from train_data.txt
    std::filesystem::path currentPath = std::filesystem::current_path();
    std::filesystem::path filePath = currentPath.parent_path() / "src" / "train_data.txt";
    
    std::ifstream inputFile(filePath);
    
    if(!inputFile.is_open()) std::cout << "Cannot open file\n";

    std::string line;

    for(int i=0; i<maximumGeneration; i++){
        while(std::getline(inputFile, line)){
            std::istringstream iss(line);
            if (line=="\n" || line=="\t" || line.empty()) break;

            largestFitness = 0;
            fitness.resize(0);
            if(Const::dimensionOfBuffer==1){
                if(Const::typeOfBuffer==Int){  
                    int num; 
                    for(int i=0; i<Const::shapeOfBuffer.getLength(); i++){
                        iss >> num;
                        data->set(i, num);
                    } 
                }     
                else if(Const::typeOfBuffer==Float){  
                    float num; 
                    for(int i=0; i<Const::shapeOfBuffer.getLength(); i++){
                        iss >> num;
                        data->set(i, num);
                    } 
                }  
            }
            else if(Const::dimensionOfBuffer==2){
                if(Const::typeOfBuffer==Int){  
                    int num; 
                    for(int i=0; i<Const::shapeOfBuffer.getLength(); i++){
                        for(int j=0; j<Const::shapeOfBuffer.getWidth(); j++){
                            iss >> num;
                            data->set(i, j, num);
                        }
                    } 
                }     
                else if(Const::typeOfBuffer==Float){  
                    float num; 
                    for(int i=0; i<Const::shapeOfBuffer.getLength(); i++){
                        for(int j=0; j<Const::shapeOfBuffer.getWidth(); j++){
                            iss >> num;
                            data->set(i, j, num);
                        }
                    } 
                }  
            }

            for(Program* program: population) {
                program->changeData(*data);
            }

            if(!isGenerated){
                isGenerated=true;
                generatePopulation();
            }

            evaluation();
            for (size_t i=0; i<fitness.size(); i++) fitnessAverage[i] += fitness[i];       
        }
        
        for(float fit: fitnessAverage) fit/=totalPopulation;
        crossover();

        if(counter==0) std::cout << "EVOLUTION COMPLETENESS: " << loopCounter*10 << "%\n";
        counter++;
        if(counter==int(maximumGeneration*0.1)){
            counter = 0;
            loopCounter++;
            if(loopCounter==10) std::cout << "EVOLUTION COMPLETENESS: 100%\n";
        }
    }
    //show the result to out.txt
    std::ofstream outFile("../src/out.txt");

    outFile << "Evolution done" << std::endl;
    outFile << "This is the final Program:\n";
    int infix = 0;
    for(int index: prefixReference){
        outFile << "Infix index: " << infix << ", Function name: " <<
            finalProgram->tree[index]->getFunctionName() << ", Argument: ";
        for(int i=0; i<finalProgram->tree[index]->getArity(); i++)
            outFile << finalProgram->tree[index]->argumentIndex[i] << " "; 
        outFile << ", Output index: ";
        for(int i=0; i<finalProgram->tree[index]->getOutputNumber(); i++)
            outFile << finalProgram->tree[index]->outputIndex[i] << " "; 
        outFile << "\n";
        infix++;
    }
    outFile << "Fitness: " << largestFitness << "\n";

    inputFile.close();
};
*/