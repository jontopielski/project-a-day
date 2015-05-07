#include <iostream>
using namespace std;

int fibToN( int n );

int main() {
    int userNum;
    cout << "Enter desired fibonacci number: " << endl;
    cin >> userNum;
    cout << "The " << userNum << " number in the fibonnaci sequence is "
        << fibToN( userNum ) << endl;
}

int fibToN( int n ) {
    if ( n < 2 ) return n;
    int fib1 = 1;
    int fib2 = 1;
    int temp;

    for ( int i = 2 ; i < n ; ++i ) {
        temp = fib2;
        fib2 = fib1 + fib2;
        fib1 = temp;
    }

    return fib2;
}

