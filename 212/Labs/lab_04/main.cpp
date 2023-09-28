#include "linked_list.h"
#include <string>
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
//////////////////////////////////////////////////
    LinkedList *list;
    if (rows[0].length() < 1){
    list = new LinkedList();
    
    }
    else if (rows[0].length()== 1){
     list = new LinkedList(stoi(rows[0]));
    }
    else{
        std::vector<int> first_line;
        std::istringstream iss(rows[0]);

        int num;

    while (iss >> num) {
        first_line.push_back(num);
    }
     list = new LinkedList(first_line);

    }
    std::cout << list->to_string() << std::endl;
    for(int i = 1 ; i < rows.size(); i++){
        if (rows[i].find('-') != std::string::npos){
            int del_loc = rows[i].find('-');
            rows[i]. 
        }
        else if (rows[i].find('?') != std::string::npos){

        }
        else if (rows[i].find(' ') != std::string::npos){

        }
        else {
            unsigned int num = stoi(rows[i]);
            if (num%2 == 0){
            list->push_back(num);                    //even
            }
            else{
            list->push_front(num);                     //odd
            }    

        }
        std::cout << list->to_string() << std::endl;
    }
    return 0;
}

//An integer
//odd integers get prepending to the list
//even integers get appended to the list

//A pair of integers
//val, idx to be inserted

//A negative integer
//the integer to be deleted from the list
//Note: You'll need to remove the '-' before passing the value to the function!

//An integer with a question mark
//the integer to search for in the list
//Note: Again, you'll need to remove the '?' before passing the value to your function!



