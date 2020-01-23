#include "sortedLinkedList.h"
#include "LinkedListIterator.cpp"
#include <iostream>

template<typename T>
SortedLinkedList<T>::Node::Node(T* m_data, Node* m_prev, Node* m_next)
{
    data = m_data;
    prev = m_prev;
    next = m_next;
}


template<typename T>
SortedLinkedList<T>::SortedLinkedList() {
    guard = new Node();
    guard->prev = guard;
    guard->next = guard;
    list_size=0;

}

template<typename T>
SortedLinkedList<T>::~SortedLinkedList() {
    while(size()!=0) pop();
    delete guard;

}

template<typename T>
void SortedLinkedList<T>::push(T _data)
{
    Node* target_node = find_where_should_be(_data).node;
    Node* new_node = new Node(new T(_data), target_node->prev, target_node);
    new_node->prev->next = new_node;
    new_node->next->prev = new_node;
    list_size++;
}

template<typename T>
void SortedLinkedList<T>::push(T&& _data)
{
    Node* target_node = find_where_should_be(_data).node;
    Node* new_node = new Node(std::forward<T>(_data), target_node->prev, target_node);
    new_node->prev->next = new_node;
    new_node->next->prev = new_node;
    list_size++;

}

template<typename T>
void SortedLinkedList<T>::push_back(T _data)
{
    list_size++;

    Node* target_node = end().node;
    Node* new_node = new Node(new T(_data), target_node->prev, target_node);
    new_node->prev->next = new_node;
    new_node->next->prev = new_node;
}


template<typename T>
void SortedLinkedList<T>::print()
{
    for(auto it : *this){
        std::cout<<it<<std::endl;
    }
}


template<typename T>
size_t SortedLinkedList<T>::size()
{
    return list_size;
}

template<typename T>
LinkedListIterator<T> SortedLinkedList<T>::begin()
{
    return LinkedListIterator<T>(guard->next);
}

template<typename T>
LinkedListIterator<T> SortedLinkedList<T>::end()
{
    return LinkedListIterator<T>(guard);
}

template<typename T>
T SortedLinkedList<T>::pop()
{
    auto it = begin();
    T val = *it;
    erase(it);
    return val;
}

template<typename T>
LinkedListIterator<T> SortedLinkedList<T>::find_where_should_be(T x)
{
    if (size()==0) return LinkedListIterator<T>(guard);
    for(auto it = begin();it != end();++it)
    {
        if(*it >= x) return it;
    }
    return end();
}

template<typename T>
LinkedListIterator<T> SortedLinkedList<T>::find(T x)
{
    LinkedListIterator<T> it = find_where_should_be(x);
    if(*it == x) return it;

    LinkedListIterator<T> empty_it = LinkedListIterator<T>(nullptr);
    return empty_it;
}

template<typename T>
LinkedListIterator<T> SortedLinkedList<T>::erase(LinkedListIterator<T> it)
{
    Node* target_node = it.node;
    target_node->prev->next = target_node->next;
    target_node->next->prev = target_node->prev;
    Node* next_one = target_node->next;
    delete target_node;
    list_size--;
    return LinkedListIterator<T>(next_one);
}


template<typename T>
void SortedLinkedList<T>::unique()
{
    auto it = begin();

    T last_val = *it;

    ++it;

    while(it!=end()){
        if(*it==last_val) erase(it);
        else last_val = *it;
        ++it;
    }

}

template<typename T>
void SortedLinkedList<T>::remove(T x)
{

    auto it = find(x);

    while(it.node != nullptr) {
        erase(it);
        it = find(x);
    }
}


template<typename T>
typename SortedLinkedList<T>::SortedLinkedList SortedLinkedList<T>::merge(SortedLinkedList& a, SortedLinkedList& b)
{
    SortedLinkedList ret_list = SortedLinkedList();

    LinkedListIterator<T>* not_yet_empty_list_iterator;
    SortedLinkedList* not_yet_empty_list;

    LinkedListIterator<T> ia = a.begin();
    LinkedListIterator<T> ib = b.begin();
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

