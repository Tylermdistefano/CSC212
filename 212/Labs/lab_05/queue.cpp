#include "queue.h"
#include <iostream>

Queue::Queue(){
    this->head = nullptr;
    this->size = 0;
    this->tail = head;
}

Queue::Queue(int data){
    this->head = new Node(data);
    this->size = 1;
    this->tail = head;
}

Queue::Queue(std::vector<int> vec){
    if(vec.size() == 0){
        this->head = nullptr;
        this->size = 0;
        this->tail = head;
    }else{
        this->head = new Node(vec[0]);
        Node* temp = this->head;
        this-> tail = temp;
        for(int i = 1; i < vec.size(); i++){
            temp->next = new Node(vec[i]);
            temp = temp->next;
            this->tail = temp;
            // ->    de-reference + dot operator
            //temp = (*temp).next;
        }
    }
    this->size = vec.size();
}

Queue::~Queue(){
    // Use this instead of just deleting the head if the `Node` destructor does not delete its `next`
    /*
    Node* curr = this->head;
    Node* prev = nullptr;

    while(curr != nullptr){
        prev = curr;
        curr = curr->next;
        delete prev;
    }
    */

   // If the `node` destructor destroys the Node it points to, you do not need the code above this line
   // Note: Be sure all of your `LinkedList` operations set a Node's `next` to `nullptr` before deleting it!
    delete this->head;

    this->head = nullptr;
}

int Queue::peek(){
    int front = this->head->data;
    return front;
}

void Queue::enqueue(int data){
    if(this->head == nullptr){
        this->head = new Node(data);
        this->tail = head;
    }else{
        tail->next = new Node(data);
        this->tail = tail->next;
    }

    this->size++;
}

void Queue::dequeue(){
    Node* tmp = this->head;

    if(tmp != nullptr){
        this->head = tmp->next;
        // Without this, the Node destructor will delete
        // every element in the list after 'temp'
        tmp->next = nullptr;
        delete tmp;
        
        this->size--;
    }
}

std::string Queue::to_string(){
    std::string stringified;
    Node* tmp = this->head;

    while(tmp != nullptr){
        stringified += std::to_string(tmp->data) + " ";
        tmp = tmp->next;
    }

    return stringified;
}
