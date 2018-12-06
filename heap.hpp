//
// Created by Greg on 2018-11-29.
//

#ifndef HEAP_HEAP_HPP
#define HEAP_HEAP_HPP

#include <ostream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * A heap. Accepts any STL sequence of elements.
 * @tparam T type of element stored in heap
 * @tparam Iterator the iterator for the STL sequence of elements
 */
template<class T, class Iterator>
class heap {
private:
    vector<T> _heap; // the heap as a vector of T

    /**
     * Validates the heap's contents by using std::make_heap.
     */
    void heapify() {
        make_heap(_heap.begin(),_heap.end());
    }

public:
    /**
     * Constructs a heap using a sequence of elements.
     * @param first the first element in the sequence
     * @param last the last element in the sequence
     */
    heap(Iterator first, Iterator last) {
        while(first != last) {
            _heap.emplace_back(*first);
            first++;
        }
        heapify();
    }

    /**
     * Pushes an element onto the heap.
     * @param element the element to push
     */
    void push(T element) {
        _heap.emplace_back(element);
        heapify();
    }

    /**
     * Pops an element from the heap and returns it.
     * @return the element to pop
     */
    T pop() {
        T root = _heap.at(0);
        _heap.erase(_heap.begin());
        heapify();
        return root;
    }

    /**
     * @return this heap's size
     */
    unsigned long size() {
        unsigned long size = 0;
        for (T t : _heap) {
            size += sizeof(t);
        }
        return size;
    }

    /**
     * @return true if this heap is empty
     */
    bool is_empty() {
        return _heap.empty();
    }

    /**
     * Clears the heap of all elements.
     */
    void clear() {
        _heap.erase(_heap.begin(), _heap.end());
    }

    /**
     * Puts the heap's contents into an ostream.
     * @param os the stream to put the heap's contents into
     * @param h the heap
     * @return the new ostream
     */
    friend ostream& operator << (ostream& os, const heap& h) {
        for (T t : h._heap) {
            os << t << " ";
        }
        return os;
    }

    /**
      * Implements the Memento design pattern to save heaps in memory.
      */
    class memento {
    private:
        ::heap<T, Iterator> heap;
    public:
        memento (const ::heap<T, Iterator>& h):  heap (h) {}
        ::heap<T, Iterator> snapshot() const {return heap;}
    };

    /**
     * Creates a memento of this heap.
     * @return a new memento of this heap
     */
    memento* create_memento() const {
        return new memento (*this);
    }

    /**
     * Reinstates a memento of a heap.
     * @param mem the memento to reinstate
     */
    void reinstate_memento (memento* mem) {
        *this = mem->snapshot();
    }

};

#endif //HEAP_HEAP_HPP
