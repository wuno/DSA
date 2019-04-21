//
// Created by wuno on 4/20/19.
//

#ifndef DSA_LINKEDLIST_H
#define DSA_LINKEDLIST_H
#include <iostream>
#include <cstdlib>
#include "LinkedNode.cpp"

template <class K, class D>
class LinkedList {
private:
    LinkedNode<K, D> *head, *tail;
public:
    int length;
    LinkedList();
    ~LinkedList();
    void addNode(K key, D data);
    bool deleteNode(K key);
    LinkedNode<K, D>* findNode(K key);
    int getLength();
    void printNodes();
};

#endif //DSA_LINKEDLIST_H
