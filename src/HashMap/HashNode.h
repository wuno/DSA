//
// Created by wuno on 4/20/19.
//

#ifndef DSA_HASHNODE_H
#define DSA_HASHNODE_H

template <class K, class V>
class HashNode {
private:

public:
    K key;
    V value;

    HashNode(const K &key, const V &value);
};

#endif //DSA_HASHNODE_H


