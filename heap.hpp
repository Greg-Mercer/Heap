//
// Created by herbo on 2018-11-29.
//

#ifndef HEAP_HEAP_HPP
#define HEAP_HEAP_HPP

#include <ostream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<class T>
class heap {
private:
    vector<T> _heap;

    void heapify() {
        make_heap(_heap.begin(),_heap.end());
    }

public:
    heap(typename::vector<T>::const_iterator first, typename::vector<T>::const_iterator last) {
        typename::vector<T>::const_iterator temp = first;
        while(temp != last) {
            _heap.emplace_back(*temp);
            temp++;
        }
        heapify();
    }

    void push(T element) {
        _heap.emplace_back(element);
        heapify();
    }

    T pop() {
        T root = _heap.at(0);
        _heap.erase(_heap.begin());
        heapify();
        return root;
    }

    unsigned long size() {
        unsigned long size = 0;
        for (T t : _heap) {
            size += sizeof(t);
        }
        return size;
    }

    bool is_empty() {
        return _heap.empty();
    }

    void clear() {
        _heap.erase(_heap.begin(), _heap.end());
    }

    friend ostream& operator << (ostream& os, const heap& h) {
        for (T t : h._heap) {
            os << t << " ";
        }
        os << endl;
        return os;
    }
};

#endif //HEAP_HEAP_HPP
