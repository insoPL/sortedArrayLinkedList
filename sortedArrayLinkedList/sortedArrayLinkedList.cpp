#include "sortedArrayLinkedList.h"
#include "ArrayLinkedListIterator.cpp"
#include <iostream>
#include <math.h>

template<typename T>
SortedArrayLinkedList<T>::Stage::Stage(){
    array_size = 0;
    array = new T[STAGE_SIZE];
}

template<typename T>
void SortedArrayLinkedList<T>::Stage::push(T x) {
    int i;
    for(i = array_size-1; array[i]>x; i--)
    {
        array[i+1] = array[i];
    }
    array[i+1] = x;
    array_size++;
}

template<typename T>
SortedArrayLinkedList<T>::SortedArrayLinkedList(){
    stages_size = 1;
    stages = new Stage*[MAX_STAGES];
    for(int x = 0; x< MAX_STAGES; x++) stages[x]= nullptr;
    stages[0] = new Stage();
    stages[1] = new Stage();
}

template<typename T>
void SortedArrayLinkedList<T>::push(T x){
    int which_stage = find_stage(x);
    Stage* st = stages[which_stage];

    if (st->array_size >= STAGE_SIZE){
        //przekroczono maxymalną wielkość stage
        Stage* new_stage = new Stage();
        for(int i = STAGE_SIZE/2; i<STAGE_SIZE; i++)
            new_stage->push(st->array[i]);
        st->array_size=STAGE_SIZE/2;

        int i;
        for(i = stages_size; i>which_stage; i--)
        {
            stages[i+1] = stages[i];
        }
        new_stage->push(x);
        stages[i+1] = new_stage;
        stages_size++;
    }
    else {
        st->push(x);
    }
    list_size++;
}

template<typename T>
int SortedArrayLinkedList<T>::find_stage(T x){
    for (int i = stages_size-1; i >= 0; i--){
        Stage* st = stages[i];
        if (st->array_size==0) continue;
        if (st->array[0]<x) return i;
    }
    return 0;
}

template<typename T>
inline size_t SortedArrayLinkedList<T>::size(){
    return list_size;
}

template<typename T>
void SortedArrayLinkedList<T>::print(){
    for(auto it : *this){
        std::cout<<it<<std::endl;
    }}

template<typename T>
void SortedArrayLinkedList<T>::erase(Stage* st, int it){

    for(int i = it+1; i<(st->array_size); i++){
        st->array[i-1] = st->array[i];
    }
    st->array_size--;// if arraysize ==0
}

template<typename T>
T SortedArrayLinkedList<T>::pop(){
    T ret = stages[0]->array[0];
    erase(stages[0],0);
    return ret;
}

template<typename T>
void SortedArrayLinkedList<T>::remove(T x){
    bool multiple_x = false;
    int foo = find_stage(x);
    Stage* st = stages[foo];
    int start = st->array_size;

    for(int i = 0; i<(st->array_size); i++){
        if ((st->array[i])==x){
            start = i;
            multiple_x = true;
            break;
        }
    }

    erase(st,start);

    if (multiple_x)remove(x);

}


template<typename T>
ArrayLinkedListIterator<T> SortedArrayLinkedList<T>::begin(){
    return ArrayLinkedListIterator<T>(stages, 0);
}

template<typename T>
ArrayLinkedListIterator<T> SortedArrayLinkedList<T>::end(){
    return ArrayLinkedListIterator<T>(&stages[stages_size], 0);
}