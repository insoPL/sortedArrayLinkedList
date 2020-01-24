#include <iostream>
#include "sortedArrayLinkedList/sortedArrayLinkedList.cpp"

using namespace std;

int main() {

    auto list = SortedArrayLinkedList<int>();
    for(int x = 0; x<20 ; x++)
        list.push(x);
//
//    for(int x = 0; x<10 ; x++)
//        list.remove(5);
//
//    for(int x : list) cout<<x<<' ';
//
//    SortedList<int>* lista = &list;
//
//    lista->print();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
