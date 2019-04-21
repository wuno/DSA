//
// Created by wuno on 4/18/19.
//

#ifndef DSA_HASHMAP_H
#define DSA_HASHMAP_H
#include "HashNode.cpp"
#include <iostream>
#include <cstdlib>

template <class K, class V>
class HashMap {
private:
    int TABLE_SIZE;
    int currentSize;
    HashNode<K, V> **table;
    HashNode<K, V> *dummy;
    int makeHash(K key);

public:
    HashMap(int tableSize);
    ~HashMap();
    void insertHashNode(K key, V value);
    bool deleteValue(K key);
    V getValue(K key);
    int getCurrentSize();
    int getTableSize();
    bool isEmpty();
    bool isFull();
    void printHashTable();
};

#endif //DSA_HASHMAP_H
