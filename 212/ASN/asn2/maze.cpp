#include "maze.h"

MAZE::MAZE(int seed, int row, int col){
rows = row;
cols = col;
cords.second = 0;
cords.first = 0;
std::vector<std::vector<int>> set(row, std::vector<int>(col, 15));
matrix = set;
matrix[0][0] = 7;//sets the starting block
std::srand(seed); // sets the seed for rand
position_list.push_back(cords);
genorate(seed);//runs the recursive backtracking function
matrix[rows-1][cols-1] -= 4;//sets the exit on the last block
};

MAZE::~MAZE(){

};

void MAZE::genorate(int seed){
position_list.push_back(cords);
checkforneighbors(); // checks what neighbors in the grid are posible to go to
if (neighbors.size() != 0){

int idx = std::rand() / ((RAND_MAX + 1u) / neighbors.size()); //picks random neighbor to go to 
//std::cout << idx << "rng" << std::endl;
moves(idx);
genorate(seed);
} 

else{
    position_list.pop_back();
    cords = position_list.back();
    return;
}


};

void MAZE::checkforneighbors(){
    neighbors.clear();
if(cords.first - 1>=0 && matrix[cords.first - 1][cords.second] == 15){    
    neighbors.push_back(0);
}
if(cords.first + 1 <=rows-1 && matrix[cords.first + 1][cords.second] == 15 ){
    neighbors.push_back(1);                                                //cords.second is teh current y or col cord.
}
if(cords.second + 1 <= cols-1 && matrix[cords.first][cords.second + 1] == 15){
    neighbors.push_back(2);
}
if(cords.second - 1>=0 && matrix[cords.first][cords.second -1] == 15){
    neighbors.push_back(3);
}

};

void MAZE::moves(int idx){
switch (neighbors.at(idx))
{
case 0: //move north
    
    matrix[cords.first][cords.second] -= 8; //changes the current block to be correct.
    matrix[cords.first-1][cords.second] -= 4; //changes next to corrent value 
    
    cords.first --; // updates current location
    break;

case 1: //move south
    matrix[cords.first][cords.second] -= 4;
    matrix[cords.first+1][cords.second] -= 8; 

    cords.first ++;
    break;

case 2: //move east
    matrix[cords.first][cords.second] -= 2; 
    matrix[cords.first][cords.second+1]-= 1; 

    cords.second ++;
    break;

case 3: // move west
    matrix[cords.first][cords.second] -= 1; 
    matrix[cords.first][cords.second-1] -= 2; 

    cords.second --;
    break;

default:
    std::cout<< "Not correct idx value." << std::endl;
}

}
