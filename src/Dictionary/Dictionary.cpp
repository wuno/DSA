//
// Created by wuno on 4/14/19.
//

#include "Dictionary.h"

template <class K, class V>
void Dictionary<K, V>::insertNode(K key, V value) {
    if ( Node.find(key) == Node.end() ) {
        Node.insert({key, value});
    } else {
       Node[key] = value;
    }

    std::cout << "Running Dictionary..." << "\n";
    for (auto itr = Node.find("Nick"); itr != Node.end(); itr++) {
        std::cout << itr->first << '\t' << itr->second << '\n';
    }
}

template <class K, class V>
void Dictionary<K, V>::deleteNode(K key) {
    Node.erase({key});

    std::cout << "Running Dictionary..." << "\n";
    for (auto itr = Node.find("Nick"); itr != Node.end(); itr++) {
        std::cout << itr->first << '\t' << itr->second << '\n';
    }
}

template <class K, class V>
bool Dictionary<K, V>::findNode(K key) {
    if ( Node.count(key) > 0 ) {
        std::cout << "Found the key - " << key << '\n';
        return true;
    } else {
        std::cout << "Could not find the key - " << key << '\n';
        return false;
    }
}