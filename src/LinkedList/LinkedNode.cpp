//
// Created by wuno on 4/20/19.
//

#include "LinkedNode.h"

template <class K, class D>
LinkedNode<K, D>::LinkedNode(const K &key, const D &data) :
        key(key), data(data) {}