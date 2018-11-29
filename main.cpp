#include <iostream>
#include <vector>
#include "heap.hpp"

int main() {

    vector<int> v = {5, 8, 10, 9, 1, 2};
    heap<int> h{v.begin(), v.end()};
    h.push(6);
    cout << h.pop() << endl;
    cout << h << endl;
    cout << h.size() << endl;
    cout << h.is_empty() << endl;
    h.clear();
    cout << h.is_empty() << endl;


    return 0;
}