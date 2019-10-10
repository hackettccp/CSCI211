/**
 * Demonstrates the basic use of Lists.
 */
#include <iostream>
#include <list>

using namespace std;

//Prototype
void printList(list<int>);

/**
 * Main Function.
 */
int main() {
    list<int> w;
    w.push_back(4);
    w.push_back(7);
    w.push_back(11);
    w.push_front(2);
    w.push_front(77);
    printList(w);

    w.pop_front();                          //Removes first value in the list
    printList(w);
    
    w.pop_back();                           //Removes the last value in the list
    printList(w);

    list<int>::iterator t = w.begin();
    t++;
    w.erase(t);                             //Removes the value at index 1.
    printList(w);
}

/**
 * Simply prints the current values in the list.
 */
void printList(list<int> w) {
    cout << "Current values in the list: " << endl;
    list<int>::iterator t = w.begin();
    for(int i = 0; i < w.size(); i++){
		cout << *t << " ";
		t++;
    }
    cout << endl;
}