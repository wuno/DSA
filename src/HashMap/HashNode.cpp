//
// Created by wuno on 4/20/19.
//

#include "HashNode.h"

template <class K, class V>
HashNode<K, V>::HashNode(const K &key, const V &value) :
    key(key), value(value) {}