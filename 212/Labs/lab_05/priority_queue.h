#include "priority_node.h"
#include <vector>
#include <string>
#include <utility>
class PQueue{
    private:
        Node* head;
        Node* tail;
        unsigned int size;

    public:
        PQueue(); // this->head = nullptr;
        PQueue(int data, int priority);
        PQueue(std::vector<std::pair<int,int>> vec);
        ~PQueue();

        void push_front(int data);
        int peek();
        void enqueue(int data);
        void dequeue();
        std::string to_string();
};