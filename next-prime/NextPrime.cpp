#include <iostream>
#include <queue>
#include <math.h>
#include "NextPrime.hpp"
using namespace std;

int main() {
    std::queue<int> primes;
    char input;
    int currentElement;

    primes.push( 2 );
    primes.push( 3 ); 
    while ( true ) {
        cout << "Do you want the next prime? ( 'y' = yes, 'n' = no )" << endl;
        cin >> input;
        if ( input != 'y' && input != 'n' ) {
            cerr << "Invalid input!" << endl;
            continue;
        }

        if ( input == 'n' ) {
            break;
        }

        cout << "The next prime is " << primes.front() << endl;
        primes.pop();

        if ( primes.size() == 1 ) {
            while ( primes.size() < 8 ) {
                currentElement = primes.back();
                primes.push( findNextPrime( currentElement ) );
            }
        }
    }

    return EXIT_SUCCESS;
}

int findNextPrime( int num ) {
    while ( true ) {
        num += 2;
        if ( isPrime( num ) ) {
            break;
        }
    }

    return num;
}

bool isPrime( int val ) {
    if ( val % 2 == 0 && val != 2 ) return false;
    if ( val < 16 ) {
        if ( val == 9 || val == 15 ) {
            return false;
        }
        return true;
    }

    for ( int i = 3 ; i * i <= val ; i += 2 ) {
        if ( val % i == 0 ) {
            return false;
        }
    }

    return true;
}
