#ifndef AISDPROJEKT_ARRAYLISTITERATOR_H
#define AISDPROJEKT_ARRAYLISTITERATOR_H

#include "sortedArrayList.h"

template <typename T>
class ArrayListIterator : public Iterator<T>
{
    friend  SortedArrayList<T>;
    T* array_pos;
    ArrayListIterator(T* _array);
public:
    ArrayListIterator& operator++();
    ArrayListIterator& operator--();
    bool operator!=(const Iterator<T>& other);
    bool operator==(const Iterator<T>& other);
    T& operator*();
    T& operator*() const ;
};

#endif //AISDPROJEKT_ARRAYLISTITERATOR_H
