//
// Created by wuno on 4/18/19.
//

#include "HashMap.h"
#include "HashNode.h"

template <class K, class V>
HashMap<K, V>::HashMap(int tableSize) {
    TABLE_SIZE = tableSize;
    currentSize = 0;
    table = new HashNode<K, V>*[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; ++i) {
        table[i] = NULL;
        dummy = new HashNode<K, V> (-1, -1);
    }
}

template <class K, class V>
HashMap<K, V>::~HashMap() {
    delete table;
    delete dummy;
}

template <class K, class V>
int HashMap<K, V>::makeHash(K key) {
    return key % TABLE_SIZE;
}

template <class K, class V>
void HashMap<K, V>::insertHashNode(K key, V value) {

    // Crete a temporary node
    HashNode<K, V> *temp = new HashNode<K, V>(key, value);
    // Create a Hash Index
    int hashIndex = makeHash(key);

    // Find a free space that is not marked as deleted
    while (table[hashIndex] != NULL && table[hashIndex] && table[hashIndex]->key != -1) {
        hashIndex++;
        hashIndex %= TABLE_SIZE;
    }

    // If a new node is entered increase the size of the hash table
    if (table[hashIndex] == NULL || table[hashIndex]->key == -1) {
        currentSize++;
        table[hashIndex] = temp;
    }
}

template <class K, class V>
bool HashMap<K, V>::deleteValue(K key) {
    int hashIndex = makeHash(key);

    while(table[hashIndex] != NULL) {
        if(table[hashIndex]->key == key) {
            std::cout << "Hash Map Running..." << "\n";
            std::cout << "Hash Map Delete Value By Key [Best/Worst: O(1)]" << "\n";
            std::cout << "\n" << " Key " << key << " Does Exist / Value is... " << table[hashIndex]->value << "\n";
            std::cout << "\n" << "\n";

            table[hashIndex] = dummy;
            currentSize--;
            return true;
        }
        hashIndex++;
        hashIndex %= TABLE_SIZE;
    }

    std::cout << "Hash Map Running..." << "\n";
    std::cout << "Hash Map Delete Value By Key [Best/Worst: O(1)]" << "\n";
    std::cout << "\n" << " Key Does Not Exist / Value is... " << "\n";
    std::cout << "\n" << "\n";

    return false;
}

template <class K, class V>
V HashMap<K, V>::getValue(K key) {
    int hashIndex = makeHash(key);
    int counter = 0;
     while(table[hashIndex] != NULL) {
         if(counter++ > TABLE_SIZE) {
             std::cout << "Hash Map Running..." << "\n";
             std::cout << "Hash Map Returning Value By Key [Best/Worst: O(1)]" << "\n";
             std::cout << " \n" << "Key " << key << " Does Not Exist..." << "\n" << "\n";
             return 0;
         }
         if(table[hashIndex]->key == key) {
             std::cout << "Hash Map Running..." << "\n";
             std::cout << "Hash Map Returning Value By Key [Best/Worst: O(1)]" << "\n";
             std::cout << " \n" << "Value = " << table[hashIndex]->value << "\n" << "\n";
             return table[hashIndex]->value;
         }
         hashIndex++;
         hashIndex %= TABLE_SIZE;
     }
}

template <class K, class V>
int HashMap<K, V>::getCurrentSize() {
    std::cout << "Hash Map Current Size Is... " << currentSize << "\n" << "\n";
    return currentSize;
}

template <class K, class V>
int HashMap<K, V>::getTableSize() {
    std::cout << "Hash Map Table Size Is... " << TABLE_SIZE << "\n" << "\n";
    return TABLE_SIZE;
}

template <class K, class V>
bool HashMap<K, V>::isEmpty() {
    if(currentSize == 0) {
        return true;
    } else {
        return false;
    }
}

template <class K, class V>
bool HashMap<K, V>::isFull() {
    if(TABLE_SIZE == currentSize) {
        return true;
    } else {
        return false;
    }
}

template <class K, class V>
void HashMap<K, V>::printHashTable() {
    std::cout << "Hash Map Printing..." << "\n";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if(table[i] != NULL && table[i]->key != -1) {
            std::cout << "Key = " << table[i]->key << " Value = " << table[i]->value << "\n" << "\n";
        }
    }
    std::cout << "\n" << "\n";
}
