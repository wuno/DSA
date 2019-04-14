//
// Created by wuno on 4/14/19.
//

#include "Dictionary.h"

template <class K, class V>
void Dictionary<K, V>::insertNode(K key, V value) {
    std::cout << "Running Dictionary insertNode(K key, V value)..." << "\n";
    if ( Node.find(key) == Node.end() ) {
        Node.insert({key, value});
    } else {
       Node[key] = value;
    }
    for (auto it = Node.find("Nick"); it != Node.end(); it++) {
        std::cout << it->first << '\t' << it->second << '\n';
    }
    std::cout << "\n" << "\n";
}

template <class K, class V>
void Dictionary<K, V>::deleteNode(K key) {
    std::cout << "Running Dictionary deleteNode(K key)..." << "\n";
    Node.erase({key});
    for (auto itr = Node.find("Nick"); itr != Node.end(); itr++) {
        std::cout << itr->first << '\t' << itr->second << '\n';
    }
    std::cout << "\n" << "\n";
}

template <class K, class V>
bool Dictionary<K, V>::findNode(K key) {
    std::cout << "Running Dictionary findNode(K key)..." << "\n";
    if ( Node.count(key) > 0 ) {
        std::cout << "Found the key - " << key << '\n';
        return true;
    } else {
        std::cout << "Could not find the key - " << key << '\n';
        return false;
    }
    std::cout << "\n" << "\n";
}

template <class K, class V>
void Dictionary<K, V>::getKeys() {
    std::cout << "Running Dictionary getKeys()..." << "\n";
    for(auto it = Node.begin(); it != Node.end(); ++it) {
        std::cout << it->first << "\n";
    }
    std::cout << "\n" << "\n";
}

template <class K, class V>
void Dictionary<K, V>::getValues() {
    std::cout << "Running Dictionary getValues()..." << "\n";
    for(auto it = Node.begin(); it != Node.end(); ++it) {
        std::cout << it->second << "\n";
    }
    std::cout << "\n" << "\n";
}