//
// Created by lukas on 1/23/20.
//

#ifndef AISDPROJEKT_ITERATOR_H
#define AISDPROJEKT_ITERATOR_H

template<typename T>
class Iterator {
    Iterator<T>& operator++();
    Iterator& operator--();
    T operator*();
    bool operator!=(const Iterator& other);
    bool operator==(const Iterator& other);
};


#endif //AISDPROJEKT_ITERATOR_H
