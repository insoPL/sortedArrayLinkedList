#include "sortedArrayList.h"
#include "ArrayLinkedListIterator.cpp"
#include <iostream>
#include <math.h>


template<typename T>
inline size_t SortedArrayList<T>::capacity(){
    return (size_t) (pow(stage_incr,stage)*stage_size);
}

template<typename T>
SortedArrayList<T>::SortedArrayList(){
    stage = 1;
    data_array = new T[capacity()];
    array_size=0;
}

template<typename T>
SortedArrayList<T>::SortedArrayList(T* init_array, const size_t init_array_size){
    stage = 1;
    while(capacity()<init_array_size) stage++;

    data_array = new T[capacity()];
    array_size=0;

    for(int x=0; x<init_array_size; x++)
    {
        data_array->push(init_array[x]);
    }
}

template<typename T>
SortedArrayList<T>::~SortedArrayList(){
    delete data_array;
}


template<typename T>
ArrayLinkedListIterator<T> SortedArrayList<T>::find(T searched_value){
    if(searched_value<=data_array[0]) return begin();
    else if(searched_value>data_array[size()-1]) return end();

    int min_p = 0;
    int max_p = size();

    int halfway_p=0;
    do{
        halfway_p = (max_p-min_p)/2+min_p;
        if(data_array[halfway_p]>=searched_value ) max_p -= (max_p-min_p+1)/2;
        else min_p += (max_p-min_p+1)/2;
    }while(min_p!=max_p);

    if (data_array[min_p] != searched_value) ArrayLinkedListIterator<T>(nullptr);
    return ArrayLinkedListIterator<T> (&data_array[min_p]);
}

template<typename T>
size_t SortedArrayList<T>::size()  {
    return array_size;
}

template<typename T>
void SortedArrayList<T>::print()
{
    for(auto it : *this){
        std::cout<<it<<std::endl;
    }
}


template<typename T>
void SortedArrayList<T>::resize()
{
    while(capacity() <= size()) stage++;
    T* old_array = data_array;
    data_array = new T[capacity()];
    for(size_t x=0; x<size(); x++)
    {
        data_array[x] = old_array[x];
    }
    delete old_array;
}

template<typename T>
void SortedArrayList<T>::push(T x) {
    if (size()>=capacity()) resize();
    ArrayLinkedListIterator<T> il = end();
    ArrayLinkedListIterator<T> ir = end();
    --il;

    while(x<*il)
    {
        *ir = *il;
        --ir;
        --il;
    }
    *ir = x;
    array_size++;
}

template<typename T>
void SortedArrayList<T>::push_back(T x) {
    if (size()>=capacity()) resize();

    ArrayLinkedListIterator<T> iter = end();

    T bar = x;
    while(iter != end())
    {
        T foo = *iter;
        *iter = bar;
        bar = foo;
        ++iter;
    }
    *iter = bar;
    array_size++;
}

template<typename T>
void SortedArrayList<T>::remove(T x){
    /* W przypadku usuwania pojedynczego elementu szybsza byla by metoda podobna do tej uzytej w metodzie push
     * zdecydowalem sie uzyc binary search zeby zoptymalizowac scenariusz usuwajacy wiele obiektow tej samej wartosci
    */

    ArrayLinkedListIterator<T> start_pos = find(x);
    if (start_pos == ArrayLinkedListIterator<T>(nullptr)) return;
    ArrayLinkedListIterator<T> end_pos = start_pos;
    while(start_pos != end() && x == *end_pos) ++end_pos;
    remove_pos(start_pos, end_pos);
}

template<typename T>
T SortedArrayList<T>::pop() {
    T val = *begin();
    erase(begin());
    return val;
}

template<typename T>
ArrayLinkedListIterator<T> SortedArrayList<T>::erase(ArrayLinkedListIterator<T> i) {
    auto b = i;
    remove_pos(i, ++b);
    return i;
}

template<typename T>
void SortedArrayList<T>::remove_pos(ArrayLinkedListIterator<T> pos_start, ArrayLinkedListIterator<T> pos_end) {
    while(pos_end != end()){
        *pos_start=*pos_end;
        ++pos_start;
        ++pos_end;
    }
    int i = array_size;
    while(pos_start!=pos_end){
        i--;
        ++pos_start;
    }
    array_size=i;
}

template<typename T>
void SortedArrayList<T>::unique(){
    auto pos_start = begin();
    while(pos_start!=end())
    {
        auto end_pos = pos_start;
        while(++end_pos!=end()&&*pos_start==*end_pos) {}
        if(end_pos!=pos_start) remove_pos(++pos_start, end_pos);
        ++pos_start;
    }
}

template<typename T>
ArrayLinkedListIterator<T> SortedArrayList<T>::begin()
{
    return ArrayLinkedListIterator<T> (data_array);
}

template<typename T>
ArrayLinkedListIterator<T> SortedArrayList<T>::end()
{
    return ArrayLinkedListIterator<T> (&data_array[size()]);
}

template<typename T>
SortedArrayList<T> SortedArrayList<T>::merge(SortedArrayList& a, SortedArrayList& b)
{
    SortedArrayList ret_list = SortedArrayList();

    ArrayLinkedListIterator<T>* not_yet_empty_list_iterator;
    SortedArrayList* not_yet_empty_list;

    ArrayLinkedListIterator<T> ia = a.begin();
    ArrayLinkedListIterator<T> ib = b.begin();
    while(true)
    {
        if(ia==a.end())
        {
            not_yet_empty_list_iterator=&ib;
            not_yet_empty_list=&b;
            break;
        }
        if(ib==b.end())
        {
            not_yet_empty_list_iterator=&ia;
            not_yet_empty_list=&a;
            break;
        }

        if(*ia<*ib)
        {
            ret_list.push_back(*ia);
            ++ia;
        }
        else
        {
            ret_list.push_back(*ib);
            ++ib;
        }

    }
    while(*not_yet_empty_list_iterator!=not_yet_empty_list->end())
    {
        ret_list.push_back(**not_yet_empty_list_iterator);
        ++*not_yet_empty_list_iterator;
    }
    return ret_list;

}
