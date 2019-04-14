//
// Created by wuno on 4/14/19.
//

#ifndef DSA_DICTIONARY_H
#define DSA_DICTIONARY_H
#include <iostream>
#include <vector>
#include <map>

template <typename K, typename V>
class Dictionary {
private:
    std::map<K, V> Node;
public:
    void insertNode(K key, V value);
    void deleteNode(K key);
    bool findNode(K key);
};


#endif //DSA_DICTIONARY_H
