#include <iostream>
#include "sortedArrayLinkedList/sortedArrayLinkedList.cpp"

using namespace std;

int main() {

    auto list = SortedArrayLinkedList<int>();
    for(int x = 0; x<20 ; x++)
        list.push(x);

    for(int x = 0; x<5 ; x++)
        list.push(9);

    list.push(5);

    list.remove(5);

    cout<<"print list using iterators:"<<endl;
    for(int x : list) cout<<x<<' '<<endl;

    cout<<"pop single element"<<endl;
    cout<< list.pop()<<endl<<endl;

    SortedList<int>* lista = &list;

    cout<<"print using OOP:"<<endl;
    lista->print();

    return 0;
}
