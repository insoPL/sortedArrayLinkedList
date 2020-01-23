#include <iostream>
#include "sortedLinkedList/sortedLinkedList.cpp"

using namespace std;

int main() {

    auto list = SortedLinkedList<int>();
    for(int x = 0; x<50 ; x++)
        list.push(x);

    for(int x : list) cout<<x<<' ';

    LinkedListIterator<int> abc = list.begin();
    LinkedListIterator<int> end = list.end();

    Iterator<int>* ii = &abc;

    while (*ii != end){
        ++(*ii);
        cout<<**ii;


    }


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
