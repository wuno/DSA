//
// Created by wuno on 4/21/19.
//

#ifndef DSA_QUEUE_H
#define DSA_QUEUE_H
#include <iostream>
#include <cstdlib>

template <class T>
class Queue {
private:
    struct Node {
        T item;
        Node *next;
    };
    Node *front;
    Node *last;
    int currentSize;


public:
    Queue();
    ~Queue();
    void addNode(T item);
    struct Node* popNode();
    bool removeNode(T item);
    void printQueue();
};

#endif //DSA_QUEUE_H
