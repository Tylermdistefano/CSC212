#include "queue.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char* argv[]){

    Queue* que;
    std::string file_name(argv[1]);

	std::vector<int> file_data;
    std::string line;

	std::ifstream file(file_name);

    // Read the first line from the file & store into vector
    std::getline(file, line);

    std::stringstream ss(line);

    int temp_int;
    while(ss >> temp_int){
        file_data.push_back(temp_int);
    }

    if(file_data.size() == 0){
        que = new Queue();
    }
    else if (file_data.size() == 1){
        que = new Queue(file_data[0]);
    }
    else{
        que = new Queue(file_data);
    }

    std::cout << que->to_string() << std::endl;

    // Read the rest of the file
    while(std::getline(file, line)){
        std::stringstream ss(line);
        std::string temp;
        std::vector<std::string> line_vals;

        // Get all entries on this line
        while(ss >> temp){
            line_vals.push_back(temp);
        }


        if(line_vals[0][line_vals[0].size() - 1] == '-'){
        que->dequeue();
        std::cout << que->to_string() << std::endl; 
        }
            // 1 entry, is there a ? at the end?
        else if(line_vals[0][line_vals[0].size() - 1] == '?') {
        std::cout << que->peek() << std::endl;
        } 
        else{
        int num = stoi(line_vals[0]);
        que->enqueue(num);
        std::cout << que->to_string() << std::endl;
        }
    }

return 0;
}