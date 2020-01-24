#include <iostream>
#include "sortedArrayLinkedList/sortedArrayLinkedList.cpp"

using namespace std;

int main() {

    auto list = SortedArrayLinkedList<int>();
    for(int x = 0; x<20 ; x++)
        list.push(x);

    list.push(5);

//    for(int x = 0; x<10 ; x++)
    list.remove(5);


    for(int x : list) cout<<x<<' '<<endl;

    cout<< list.pop()<<endl<<endl;

    list.print();
//
//    SortedList<int>* lista = &list;
//
//    lista->print();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
