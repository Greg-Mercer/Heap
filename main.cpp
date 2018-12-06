#include <iostream>
#include <vector>
#include "heap.hpp"

int main() {

    vector<int> v = {5, 8, 10, 9, 1, 2, 11};
    heap<int, vector<int>::iterator> h{v.begin(), v.end()};
    cout << "Original heap: " << h << endl;
    heap<int, vector<int>::iterator>::memento m{h};
    h.push(6);
    cout << "Pushed 6, popping " << h.pop() << endl;
    cout << "New heap: " << h << endl;
    cout << "Heap size: " << h.size() << endl;
    cout << "Is the heap empty? " << h.is_empty() << endl;
    h.clear();
    cout << "Cleared!" << endl;
    cout << "Is the heap empty? " << h.is_empty() << endl;
    h.reinstate_memento(&m);
    cout << "Memento of original heap: " << h << endl;

    return 0;
}