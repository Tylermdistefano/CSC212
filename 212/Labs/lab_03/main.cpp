#include "DynamicArray.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

int main (int argc, char *argv[]){

std::fstream newfile;
std::string file_name = argv[1];

std::vector<int>nums;
std::ifstream inputFile(file_name);
DynamicArray *setArray;
    
    int num;
    while (inputFile >> num) {
        nums.push_back(num);
    }
    
    inputFile.close();

if(argc == 2){
setArray = new DynamicArray();

}
else if (argc == 4)
{
double scaling_factor = std::stod(argv[2]);
unsigned int capacity = std::stoul(argv[3]);
setArray = new DynamicArray(scaling_factor, capacity);

}
else{
double scaling_factor = std::stod(argv[2]);
unsigned int length = std::stoul(argv[3]);
int default_value = std::stoi(argv[4]);
setArray = new DynamicArray(scaling_factor, length, default_value);
}

//tests
unsigned int vector_size = nums.size();
unsigned int half = vector_size/2;

for (unsigned int i = 0 ; i < half ; i++){
    setArray->append(nums[i]);
}

std::cout << setArray->to_string() << std::endl;
for (unsigned int i = half ; i < vector_size ; i++){
    setArray->prepend(nums[i]);
}
std::cout << setArray->to_string() << std::endl;

unsigned int mysval = vector_size/3;
unsigned int index;
std::cout << setArray->find_first_of(nums[mysval], &index) << "\t" << index << std::endl;
std::cout << setArray->find_last_of(nums[mysval], &index) << "\t" << index << std::endl;
setArray->remove_last();
std::cout << setArray->to_string() << std::endl;
setArray->remove_first();
std::cout << setArray->to_string() << std::endl;
setArray->clear();
std::cout << setArray->to_string() << std::endl;

    return 0;
}