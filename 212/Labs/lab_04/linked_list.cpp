#include "linked_list.h"
#include <iostream>


LinkedList::LinkedList(){
    this ->head = new Node();
    this ->size = 1;
}
//test for git hub

LinkedList::LinkedList(int data){
 this-> head = new Node(data); 
 this-> size = 1;

}


LinkedList::LinkedList(std::vector<int> vec){
    this->head = new Node(vec[0]);
    this->size = 1;
    for(unsigned int i = 1 ; i < vec.size() ; i++){
        push_back(vec[i]);
    }
    
    
}

LinkedList::~LinkedList(){
while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


void LinkedList::push_front(int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    size++;
}

void LinkedList::push_back(int data){
 Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
       
}

void LinkedList::insert(int data, int idx){
Node* current = head;
for(int i = 0 ; i < idx-1 ; i++){
    current = current->next;
}
 Node* newNode = new Node(data);
 newNode->next = current->next;
        current->next = newNode;
        size++;


}

void LinkedList::remove(int data){
 Node* current = head;
    if(current->data == data){
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
        }

 Node* current = head;
    while (current->next != nullptr && current->next->data != data) {
        current = current->next;
    }
    
    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        size--;
    }

    
}


bool LinkedList::contains(int data){
    Node* current = head;
        while (current->next != nullptr) {
            if(current->data == data){
                return true;
            }
        }
    return false;   
}


int LinkedList::get_size(){
    return this->size;
}

// O(n)
std::string LinkedList::to_string(){
    std::string stringified;
    Node* tmp = this->head;

    while(tmp != nullptr){
        stringified += std::to_string(tmp->data) + " ";
        tmp = tmp->next;
    }

    return stringified;
}
