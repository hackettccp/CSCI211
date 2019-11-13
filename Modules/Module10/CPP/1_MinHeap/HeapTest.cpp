/**
 * Demonstrates using a Min-Heap
 */
#include<iostream>
#include<stdexcept>
#include "MinHeap.h"

int main() {
    MinHeap h;

    h.add(3);
    h.add(2);
    h.add(9);
    h.add(4);
    h.add(7);
    //h.dumpHeap();

    h.add(8);
    h.add(10);
    h.add(5);
    h.add(1);
    h.add(6);
    //h.dumpHeap();

    while(!h.isEmpty()) {
        cout << "Value pulled from heap: " << h.remove() << endl;
        //h.dumpHeap();
    }
}