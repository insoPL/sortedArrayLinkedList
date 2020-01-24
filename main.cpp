#include <iostream>
#include "sortedLinkedList/sortedLinkedList.cpp"
#include "sortedArrayList/sortedArrayLinkedList.cpp"

using namespace std;

int main() {

    auto list = SortedArrayList<int>();
    for(int x = 0; x<50 ; x++)
        list.push(4);

    for(int x = 0; x<10 ; x++)
        list.remove(5);

    for(int x : list) cout<<x<<' ';

    SortedList<int>* lista = &list;

    lista->print();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
