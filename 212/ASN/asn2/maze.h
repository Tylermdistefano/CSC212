#include <vector>
#include<cstdlib>
#include <utility>
#include <iostream>
#include <random>
class MAZE
{
private:
        MAZE(int row, int col)
    {
       
    }

    int rows,cols;
    std::pair<int,int> cords;//the current pos
    std::vector<int> neighbors;//cords of neighbors that have been checked to see if inbounds and not visited
    std::vector<std::pair<int,int>> position_list;// positions used for backtracking
    
    void checkforneighbors();
    void genorate(int seed);
    void moves(int idx);
    
public:
    std::vector<std::vector<int>> matrix;//the final matrix
    MAZE(int seed, int row, int col);
    ~MAZE();
    
};

