#ifndef AISDPROJEKT_LINKEDLISTITERATOR_H
#define AISDPROJEKT_LINKEDLISTITERATOR_H

#include "sortedLinkedList.h"
#include "../Iterator.h"

template<typename T>
class LinkedListIterator : public Iterator<T>
{
    friend SortedLinkedList<T>;
    typename SortedLinkedList<T>::Node* node;
    LinkedListIterator(typename SortedLinkedList<T>::Node* _node);
public:
    LinkedListIterator<T>& operator++();
    LinkedListIterator<T>& operator--();
    bool operator!=(const Iterator<T>& other);
    bool operator==(const Iterator<T>& other);
    T& operator* ();
    T& operator*() const ;

};

#endif //AISDPROJEKT_LINKEDLISTITERATOR_H
