#ifndef AISDPROJEKT_SORTEDARRAYLINKEDLIST_H
#define AISDPROJEKT_SORTEDARRAYLINKEDLIST_H

#include "../Iterator.h"
#include "../SortedList.h"
#include <cstddef>

template <typename T>
class ArrayLinkedListIterator;

template<typename T>
class SortedArrayLinkedList :SortedList<T>{
#define STAGE_SIZE 16
#define MAX_STAGES 100

    friend  ArrayLinkedListIterator<T>;

    struct Stage {
        size_t array_size;
        T *array;

        Stage();
        void push(T);
    };

    size_t stages_size;
    Stage **stages;
    size_t list_size;
    int find_stage(T);
    void erase(Stage* st, int it);
public:
    void unique();
    SortedArrayLinkedList<T>();
    void push(T);
    size_t size();
    void remove(T x);
    void print();
    T pop();

    ArrayLinkedListIterator<T> begin();
    ArrayLinkedListIterator<T> end();
};

#endif //AISDPROJEKT_SORTEDARRAYLINKEDLIST_H
