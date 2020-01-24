#ifndef AISDPROJEKT_ARRAYLINKEDLISTITERATOR_H
#define AISDPROJEKT_ARRAYLINKEDLISTITERATOR_H

#include "sortedArrayLinkedList.h"

template <typename T>
class ArrayLinkedListIterator : public Iterator<T>
{
    friend  SortedArrayLinkedList<T>;
    typename SortedArrayLinkedList<T>::Stage** stage;
    size_t pos;
    ArrayLinkedListIterator(typename SortedArrayLinkedList<T>::Stage**, size_t);
public:
    ArrayLinkedListIterator& operator++();
    ArrayLinkedListIterator& operator--();
    bool operator!=(const Iterator<T>& other);
    bool operator==(const Iterator<T>& other);
    T& operator*();
    T& operator*() const ;
};

#endif //AISDPROJEKT_ARRAYLINKEDLISTITERATOR_H
