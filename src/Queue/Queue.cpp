//
// Created by wuno on 4/21/19.
//

#include "Queue.h"

template <class T>
Queue<T>::Queue() {
    currentSize = 0;
    front = NULL;
    last = NULL;
}

template <class T>
Queue<T>::~Queue() {}

template <class T>
void Queue<T>::addNode(T item) {
    auto *temp = new Node();
    temp->item = item;
    temp->next = NULL;

    if(front == NULL) {
        front = temp;
        last = temp;
    } else {
        last->next = temp;
        last = last->next;
    }

    currentSize++;
}

template <class T>
struct Queue<T>::Node* Queue<T>::popNode() {
    if (front->next == NULL) {
        std::cout << "There is Only One Item in the Queue. Item Matches = " << front->item << "\n";
        return front;
    } else {
        std::cout << "Popped Node From Queue = " << front->item << "\n";
        front = front->next;
        currentSize--;
        return front;
    }
}

template <class T>
bool Queue<T>::removeNode(T item) {
    if(front->item == item) {
        if (front->next == NULL) {
            std::cout << "There is Only One Item in the Queue. Item Matches = " << front->item << "\n";
            return false;
        } else {
            std::cout << "Deleted Node From Queue = " << item << "\n";
            front = front->next;
            currentSize--;
            return true;
        }
    }

    Node *previous = front;
    while(previous->next != NULL && previous->next->item != item) {
        previous = previous->next;
    }

    if(previous->item != item && previous->next == NULL) {
        std::cout << "Could Not Find Item In Queue = " << item << "\n";
        return false;
    }

    previous->next = previous->next->next;
    currentSize--;
    std::cout << "Deleted Node From Queue With key = " << item << "\n";
    return true;
}

template <class T>
void Queue<T>::printQueue() {
    Node *temp = front;
    std::cout << "Queue Printing..." << "\n";
    while(temp != NULL){
        std::cout << "Queue Item Data = " << temp->item << std::endl;
        temp = temp->next;
    }
    std::cout << "\n" << "\n";
}