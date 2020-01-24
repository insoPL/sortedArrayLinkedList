#include "ArrayListIterator.h"

template<typename T>
ArrayLinkedListIterator<T>::ArrayLinkedListIterator(T* _array)
{
    array_pos = _array;
}

template<typename T>
ArrayLinkedListIterator<T>& ArrayLinkedListIterator<T>::operator++()
{
    array_pos++;
    return *this;
}

template<typename T>
ArrayLinkedListIterator<T>& ArrayLinkedListIterator<T>::operator--()
{
    array_pos--;
    return *this;
}

template<typename T>
T& ArrayLinkedListIterator<T>::operator*()
{
    return *array_pos;
}

template<typename T>
T& ArrayLinkedListIterator<T>::operator*() const
{
    return *array_pos;
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
