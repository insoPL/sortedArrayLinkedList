#ifndef AISDPROJEKT_ITERATOR_H
#define AISDPROJEKT_ITERATOR_H

template<typename T>
class Iterator {
public:
    //virtual void push(T) = 0;

    virtual T& operator*() = 0;
    virtual T& operator*() const = 0;
    virtual Iterator<T>& operator++() = 0;
    virtual Iterator<T>& operator--() = 0;
    virtual bool operator!=(const Iterator<T>&) = 0;
    virtual bool operator==(const Iterator<T>&) = 0;
};


#endif //AISDPROJEKT_ITERATOR_H
