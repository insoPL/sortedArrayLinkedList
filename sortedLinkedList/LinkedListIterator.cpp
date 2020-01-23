#include <unordered_set>
#include "LinkedListIterator.h"

template<typename T>
LinkedListIterator<T>::LinkedListIterator(typename SortedLinkedList<T>::Node *_node) {
    node = _node;
}

template<typename T>
LinkedListIterator<T>& LinkedListIterator<T>::operator++() {
    node = node->next;
    return *this;
}

template<typename T>
LinkedListIterator<T> &LinkedListIterator<T>::operator--() {
    node = node->prev;
    return *this;
}

template<typename T>
bool LinkedListIterator<T>::operator!=(const Iterator<T>& other){
    return node->data != *other;
}

template<typename T>
bool LinkedListIterator<T>::operator==(const Iterator<T>& other) {
    return node->data == *other;
}

template<typename T>
T LinkedListIterator<T>::operator*() {
    return node->data;
}

template<typename T>
T LinkedListIterator<T>::operator*() const {
    return node->data;
}
