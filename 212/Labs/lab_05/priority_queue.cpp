#include "priority_queue.h"
#include <iostream>


PQueue::PQueue(){
    this->head = nullptr;
    this->size = 0;
    this->tail = head;
}

PQueue::PQueue(int data, int priority){
    this->head = new Node(data, priority);
    this->size = 1;
    this->tail = head;
}

PQueue::PQueue(std::vector<int> vec){
    if(vec.size() == 0){
        this->head = nullptr;
        this->size = 0;
        this->tail = head;
    }else{
        this->head = new Node(vec[0],0);
        Node* temp = this->head;
        this-> tail = temp;
        for(int i = 1; i < vec.size(); i++){
            temp->next = new Node(vec[i],i);
            temp = temp->next;
            this->tail = temp;
            // ->    de-reference + dot operator
            //temp = (*temp).next;
        }
    }
    this->size = vec.size();
}

PQueue::~PQueue(){
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

int PQueue::peek(){
    int front = this->head->data;
    return front;
}

void PQueue::enqueue(int data, int priority){
    if(this->head == nullptr){
        this->head = new Node(data, priority);
        this->tail = head;
    }else{
        Node* tmp = this->head;
        while (priority >= tmp->next->priority)
        {
            tmp = tmp->next;
        }
        Node* hold=tmp->next; 
        tmp->next= new Node(data,priority);
        tmp->next->next= hold;

        if(tail->next != nullptr){
            this->tail = tail->next;
        }
        
    }

    this->size++;
}

void PQueue::dequeue(){
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

std::string PQueue::to_string(){
    std::string stringified;
    Node* tmp = this->head;

    while(tmp != nullptr){
        stringified += "(" + std::to_string(tmp->data) + "," + std::to_string(tmp->priority) + ")";
        tmp = tmp->next;
    }

    return stringified;
}
