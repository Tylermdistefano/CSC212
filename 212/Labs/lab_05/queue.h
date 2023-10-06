#include "node.h"
#include <vector>
#include <string>

class Queue{
    private:
        Node* head;
        Node* tail;
        unsigned int size;

    public:
        Queue(); // this->head = nullptr;
        Queue(int data);
        Queue(std::vector<int> vec);
        ~Queue();

        void push_front(int data);
        int peek();
        void enqueue(int data);
        void dequeue();
        std::string to_string();
};