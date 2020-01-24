#ifndef AISDPROJEKT_SORTEDLINKEDLIST_H
#define AISDPROJEKT_SORTEDLINKEDLIST_H

#include <cstddef>
#include "../Iterator.h"
#include "../SortedList.h"

template <typename T>
class LinkedListIterator;

template<typename T>
class SortedLinkedList : public SortedList<T>
{
    friend LinkedListIterator<T>;

    struct Node{       // Zagnieżdżona klasa węzła
        T* data;            // Element przechowywany przez węzeł listy
        Node* prev;     // Wskaźnik do poprzedniego węzła
        Node* next;     // Wskaźnik do kolejnego węzła
        Node(T* m_data= nullptr, Node* m_prev=nullptr, Node* m_next=nullptr);
    };

    Node* guard;
    size_t list_size;

public:
    LinkedListIterator<T> begin();
    LinkedListIterator<T> end();

    SortedLinkedList();
    ~SortedLinkedList();

    size_t size();
    void push_back(T);
    void push(T);
    void print();
    LinkedListIterator<T> find(T x);
    LinkedListIterator<T> erase(LinkedListIterator<T> i);
    T pop();
    void remove(T x);
    void unique();
    static SortedLinkedList merge(SortedLinkedList& a, SortedLinkedList& b);

};
#endif //AISDPROJEKT_SORTEDLINKEDLIST_H
