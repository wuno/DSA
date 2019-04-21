//
// Created by wuno on 4/20/19.
//

#include "LinkedList.h"
#include "LinkedNode.h"

template <class K, class D>
LinkedList<K, D>::LinkedList() {
    length = 0;
    head = NULL;
    tail = NULL;
}

template <class K, class D>
LinkedList<K, D>::~LinkedList() {}

template <class K, class D>
void LinkedList<K, D>::addNode(K key, D data) {
    auto *temp = new LinkedNode<K, D>(key, data);
    temp->data = data;
    temp->next = NULL;

    if(head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = tail->next;
    }
    length++;
}

template <class K, class D>
bool LinkedList<K, D>::deleteNode(K key) {
    if(head->key == key) {
        if (head->next == NULL) {
            std::cout << "Not Enough Nodes to Delete" << "\n";
            return false;
        } else {
            std::cout << "Deleted Node From Head With key = " << key << "\n";
            head = head->next;
            length--;
            return true;
        }
    }

    LinkedNode<K, D> *previous = head;
    while(previous->next != NULL && previous->next->key != key) {
        previous = previous->next;
    }

    if(previous->key != key && previous->next == NULL) {
        std::cout << "Could Not Find Node With Key = " << key << "\n";
        return false;
    }

    previous->next = previous->next->next;
    length--;
    std::cout << "Deleted Node From Liked List With key = " << key << "\n";
    return true;
}

template <class K, class D>
LinkedNode<K, D>* LinkedList<K, D>::findNode(K key) {
    LinkedNode<K, D> *temp = head;
    while(temp != NULL) {
        if(temp->key == key) {
            std::cout << "Linked List Finding Key..." << "\n";
            std::cout << "Linked List Found Key -> " << temp->key << " Value = " << temp->data << std::endl;
            return temp;
        }
        temp = temp->next;
    }
    std::cout << "Could Not Find The Key = " << key << "\n";
    return temp;
}

template <class K, class D>
int LinkedList<K, D>::getLength() {
    std::cout << "Linked List Running..." << "\n";
    std::cout << "Linked List Size -> " << length << std::endl;
    return length;
}

template <class K, class D>
void LinkedList<K, D>::printNodes() {
    LinkedNode<K, D> *temp = head;
    std::cout << "Linked List Running..." << "\n";
    while(temp != NULL){
        std::cout << "Node Key->" << temp->key << ": Data->" << temp->data << std::endl;
        temp = temp->next;
    }
    std::cout << "\n" << "\n";
}