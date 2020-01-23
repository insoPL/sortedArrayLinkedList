#include <iostream>
#include "sortedLinkedList/sortedLinkedList.cpp"

using namespace std;

int main() {

    auto list = SortedLinkedList<int>();
    for(int x = 0; x<50 ; x++)
        list.push(x);

    for(int x : list) cout<<x<<' ';

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
