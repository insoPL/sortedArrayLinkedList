#ifndef AISDPROJEKT_SORTEDLIST_H
#define AISDPROJEKT_SORTEDLIST_H

template<typename T>
class SortedList {
public:
    virtual void push(T) = 0;
    virtual void print() = 0;
    virtual T pop() = 0;
    virtual void remove(T x) = 0;
    virtual void unique() = 0;
    virtual size_t size() = 0;
//    virtual std::unique_ptr<SortedList<T>> begin() = 0;
//    virtual std::unique_ptr<SortedList<T>> end() = 0;



};



#endif //AISDPROJEKT_SORTEDLIST_H
