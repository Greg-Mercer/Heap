//
// Created by herbo on 2018-11-29.
//

#ifndef HEAP_HEAP_HPP
#define HEAP_HEAP_HPP

#include <ostream>

using namespace std;

template<class T>
class heap {
private:
    T* _heap;

    void heapify() {

    }

public:
    explicit heap(T* elements) {
        _heap = elements;
    }

    void push(T element) {
        _heap++;
        *_heap = element;
    }

    T pop() {
        T root = *_heap;
        _heap--;
        return root;
    }

    unsigned long size() {
        return 0;
    }

    bool is_empty() {
        return false;
    }

    void clear() {

    }

    friend ostream& operator << (ostream& os, const heap& h) {
        return os;
    }
};

#endif //HEAP_HEAP_HPP
