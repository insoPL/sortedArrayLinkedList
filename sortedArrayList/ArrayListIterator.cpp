#include "ArrayListIterator.h"

template<typename T>
ArrayListIterator<T>::ArrayListIterator(T* _array)
{
    array_pos = _array;
}

template<typename T>
ArrayListIterator<T>& ArrayListIterator<T>::operator++()
{
    array_pos++;
    return *this;
}

template<typename T>
ArrayListIterator<T>& ArrayListIterator<T>::operator--()
{
    array_pos--;
    return *this;
}

template<typename T>
T& ArrayListIterator<T>::operator*()
{
    return *array_pos;
}

template<typename T>
T& ArrayListIterator<T>::operator*() const
{
    return *array_pos;
}

template<typename T>
bool ArrayListIterator<T>::operator!=(const Iterator<T>& other)
{
    return &(**this) != &(*other);
}

template<typename T>
bool ArrayListIterator<T>::operator==(const Iterator<T>& other)
{
    return &(**this) == &(*other);
}
