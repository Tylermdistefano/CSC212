#include <vector>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <random>
class MAZE
{
private:
    int rows, cols;
    std::pair<int, int> cords;                      // the current pos
    std::vector<int> neighbors;                     // cords of neighbors that have been checked to see if inbounds and not visited
    std::vector<std::pair<int, int>> position_list; // positions used for backtracking

    void checkforneighbors(); // checks to see if there are (or how manny) neighbors there are.
    void generate(int seed);  // backtracking function to make the moves
    void moves(int idx);      // cuts the paths into the maze

public:
    std::vector<std::vector<int>> matrix; // the final matrix that gets put in the file maker.
    MAZE(int seed, int row, int col);     // constructor that builds the maze
    ~MAZE();
};
