#include "ArrayLinkedListIterator.h"

template<typename T>
ArrayLinkedListIterator<T>::ArrayLinkedListIterator(typename SortedArrayLinkedList<T>::Stage** _stage, size_t _pos)
{
    stage = _stage;
    pos = _pos;
}


template<typename T>
ArrayLinkedListIterator<T>& ArrayLinkedListIterator<T>::operator++()
{
    if (pos==((*stage)->array_size-1)) {
        stage++;
        pos = 0;
    }else{
        pos++;
    }
    return *this;
}

template<typename T>
ArrayLinkedListIterator<T>& ArrayLinkedListIterator<T>::operator--()
{
    if (pos>0) pos --;
    else {
        stage--;
        pos = (*stage)->array_size-1;
    }
    return *this;
}

template<typename T>
T& ArrayLinkedListIterator<T>::operator*()
{
    return (*stage)->array[pos];
}

template<typename T>
T& ArrayLinkedListIterator<T>::operator*() const
{
    return (*stage)->array[pos];
}

template<typename T>
bool ArrayLinkedListIterator<T>::operator!=(const Iterator<T>& other)
{
    return &(**this) != &(*other);
}

template<typename T>
bool ArrayLinkedListIterator<T>::operator==(const Iterator<T>& other)
{
    return &(**this) == &(*other);
}
