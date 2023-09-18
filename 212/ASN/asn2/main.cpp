#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "maze.h"

void create_file(int rows, int cols,std::string file_name , std::vector<std::vector<int>>matrix ){
    // Create and open a text file
    std::ofstream MyFile(file_name);

    // Write the matrix to the file
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            MyFile << matrix[i][j];
            if (j < cols -1) {
            MyFile << ' '; // Write space for all cols except the last one
            }
        }
        if (i < rows -1) {
            MyFile << '\n'; // Write newline for all rows except the last one
        }
    }

    // Close the file
    MyFile.close();

    std::cout << "Data written to filename.txt" << std::endl;
}

int main(int argc, char *argv[])
{  
    int seed = atoi(argv[1]), rows= atoi(argv[2]), cols = atoi(argv[3]); //used to get seed rows and cols 
    std::string file_name= argv[4]; //used to get file name

    MAZE newmaze(seed, rows, cols); //makes the MAZE object class.
    std::srand(seed);
    create_file(rows, cols, file_name, newmaze.matrix); //creates file and prints to it

    return 0;
    
}