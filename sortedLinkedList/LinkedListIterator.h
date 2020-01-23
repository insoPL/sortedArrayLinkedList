#ifndef AISDPROJEKT_LINKEDLISTITERATOR_H
#define AISDPROJEKT_LINKEDLISTITERATOR_H

#include "sortedLinkedList.h"

template<typename T>
class LinkedListIterator
{
    friend SortedLinkedList<T>;
    typename SortedLinkedList<T>::Node* node;
    LinkedListIterator(typename SortedLinkedList<T>::Node* _node);
public:
    LinkedListIterator<T> & operator++();
    LinkedListIterator& operator--();
    bool operator!=(const LinkedListIterator& other);
    bool operator==(const LinkedListIterator& other);
    T operator*();
};

#endif //AISDPROJEKT_LINKEDLISTITERATOR_H
