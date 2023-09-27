// C++ program to demonstrate
// the use of rand()
#include <cstdlib>
#include <iostream>
#include <vector>

int main()
{
	// This program will create some sequence of
	// random numbers on every program run
    int seed = 124343;
    std::vector<int> neighbors = {1,2,3,4,5};
    for(int i = 0 ; i < 5 ; i++){
    int idx = std::rand() / ((RAND_MAX + 1u) / neighbors.size());
    std::cout << idx << std::endl;
    }
    
    return 0;
}




