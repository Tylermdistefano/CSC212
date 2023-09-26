#include "maze.h"

MAZE::MAZE(int seed, int row, int col)
{
    rows = row;
    cols = col; // sets the size of the maze
    cords.second = 0;
    cords.first = 0; // sets the starting cords
    std::vector<std::vector<int>> set(row, std::vector<int>(col, 15));
    matrix = set;     // sets the blank maze
    matrix[0][0] = 7; // sets the starting block
    std::srand(seed); // sets the seed for rand
    position_list.push_back(cords);
    generate(seed);                  // runs the backtracking function
    matrix[rows - 1][cols - 1] -= 4; // sets the exit on the last block
};

MAZE::~MAZE(){

};

void MAZE::generate(int seed)
{
    while (position_list.size() > 0)
    {
        cords = position_list.back(); // sets the current postion to the last in the backtracking list.
        position_list.pop_back();     // removes the last element in the backtracking list.
        checkforneighbors();
        if (neighbors.size() != 0)
        {
            position_list.push_back(cords);                               // records the current position to the backtracking list.
            int idx = std::rand() / ((RAND_MAX + 1u) / neighbors.size()); // picks random neighbor to go to
            moves(idx);
            position_list.push_back(cords);
        }
    }
};

void MAZE::checkforneighbors()
{
    neighbors.clear();
    if (cords.first - 1 >= 0 && matrix[cords.first - 1][cords.second] == 15)
    {
        neighbors.push_back(0); // checks for neighbors in the north position
    }
    if (cords.first + 1 <= rows - 1 && matrix[cords.first + 1][cords.second] == 15)
    {
        neighbors.push_back(1); // checks for neighbors int the south position
    }
    if (cords.second + 1 <= cols - 1 && matrix[cords.first][cords.second + 1] == 15)
    {
        neighbors.push_back(2); // checks for neighbors in the east positon
    }
    if (cords.second - 1 >= 0 && matrix[cords.first][cords.second - 1] == 15)
    {
        neighbors.push_back(3); // checks for neighbors in the west position.
    }
};

void MAZE::moves(int idx)
{
    switch (neighbors.at(idx))
    {
    case 0: // move north

        matrix[cords.first][cords.second] -= 8;     // changes the current block to be correct.
        matrix[cords.first - 1][cords.second] -= 4; // changes next to corrent value

        cords.first--; // updates current location
        break;

    case 1: // move south
        matrix[cords.first][cords.second] -= 4;
        matrix[cords.first + 1][cords.second] -= 8;

        cords.first++;
        break;

    case 2: // move east
        matrix[cords.first][cords.second] -= 2;
        matrix[cords.first][cords.second + 1] -= 1;

        cords.second++;
        break;

    case 3: // move west
        matrix[cords.first][cords.second] -= 1;
        matrix[cords.first][cords.second - 1] -= 2;

        cords.second--;
        break;

    default:
        std::cout << "Not correct idx value." << std::endl;
    }
}
