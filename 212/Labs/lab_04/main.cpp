#include "linked_list.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char* argv[]) {

    std::string file_name = argv[1];
    std::cout << file_name << std::endl;
    std::ifstream inputFile(file_name);
    std::vector<std::string> rows;
    std::string line;
    
    while (getline(inputFile, line)) {
        rows.push_back(line);
    }

    inputFile.close();

    LinkedList *list;
    if (rows[0].length() < 1){
    list = new LinkedList();
    
    }
    else if (rows[0].length()== 1){
        LinkedList(stoi(rows[0]));
    }
    else{
        std::vector<int> first_line;
        for (int i =0 ; i < rows[0].length() ; i++){
            stoi(rows[0][i]);
            first_line.push_back();
        }


    }
    return 0;
}





