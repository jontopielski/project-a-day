#include <iostream>
using namespace std;

class List {
    List* next;
    int val;
public:
    int getVal() {
        return val;
    }
    List( int value );
};

List::List( int value ) {
    val = value;
    next = nullptr;
}
