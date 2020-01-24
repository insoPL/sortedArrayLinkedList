#ifndef AISDPROJEKT_SORTEDARRAYLIST_H
#define AISDPROJEKT_SORTEDARRAYLIST_H

#include "../Iterator.h"
#include "../SortedList.h"
#include <cstddef>

template <typename T>
class ArrayListIterator;

template<typename T>
class SortedArrayList : public SortedList<T>
{
    #define stage_size 1000
    #define stage_incr 5
    #define max_stages 10

    int stage;
    T* data_array;
    size_t array_size;

    void resize();
    void remove_pos(ArrayLinkedListIterator<T> pos_start, ArrayLinkedListIterator<T> pos_end);

public:
    SortedArrayList();
    SortedArrayList(T* init_array, const size_t init_array_size);
    ~SortedArrayList();

    size_t capacity();

    size_t size();
    void push_back(T);
    void push(T);
    void print();
    ArrayLinkedListIterator<T> find(T x);
    ArrayLinkedListIterator<T> erase(ArrayLinkedListIterator<T> i);
    T pop();
    void remove(T x);
    void unique();
    static SortedArrayList merge(SortedArrayList& a, SortedArrayList& b);

    ArrayLinkedListIterator<T> begin();
    ArrayLinkedListIterator<T> end();

};

#endif // AISDPROJEKT_SORTEDARRAYLIST_H
