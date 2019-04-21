//
// Created by wuno on 4/20/19.
//

#ifndef DSA_LINKEDNODE_H
#define DSA_LINKEDNODE_H

template <class K, class D>
class LinkedNode {
private:

public:
    LinkedNode *next;
    K key;
    D data;
    LinkedNode(const K &key, const D &data);
};

#endif //DSA_LINKEDNODE_H
