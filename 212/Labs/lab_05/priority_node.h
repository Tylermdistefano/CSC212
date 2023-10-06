#pragma once


// head
//  5  ->  3  ->  8  ->  6  -> X
// p1


class Node{
    private:
        int data;
        int priority;
        Node* next;

        friend class PQueue;
    public:
        Node();
        // Overloading
        Node(int data, int priority);
        Node(int data, Node* next);
        ~Node();
};
