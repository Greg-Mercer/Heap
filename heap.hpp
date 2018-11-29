//
// Created by herbo on 2018-11-29.
//

#ifndef HEAP_HEAP_HPP
#define HEAP_HEAP_HPP

#include <ostream>
#include <iostream>

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
        *_heap = NULL;
        _heap--;
        return root;
    }

    unsigned long size() {
        unsigned long size = 0;
        for (T *p = _heap; p != end; ++p) {
            size += sizeof(T);
        }
        return size;
    }

    bool is_empty() {
        return _heap; // non-null pointers are implicitly converted to true
    }

    void clear() {
        _heap = NULL;
    }

    friend ostream& operator << (ostream& os, const heap& h) {
        for (T *p = h._heap; p != end; ++p) {
            os << *p << " ";
        }
        os << endl;
        return os;
    }
};

#endif //HEAP_HEAP_HPP
