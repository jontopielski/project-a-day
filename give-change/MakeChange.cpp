#include <iostream>
using namespace std;

void giveChange( double diff );

int main() {
    double cost, amtGiven;
    cout << "Enter the cost of the item." << endl;
    try {
        cin >> cost;
    } catch ( std::string s ) {
        cerr << "Exception " << s << " caught!" << endl;
        return EXIT_FAILURE;
    }
    cout << "Enter amount of money tendered." << endl;
    cin >> amtGiven;

    if ( amtGiven < cost ) {
        cerr << "Cannot afford item." << endl;
        cerr << "Try putting more virtual money next time." << endl;
        return EXIT_FAILURE;
    }

    giveChange( amtGiven - cost );
}

void giveChange( double diff ) {
    int pennies = 0, nickels = 0, dimes = 0, quarters = 0, ones = 0,
        fives = 0, tens = 0, twenties = 0, fifties = 0, hundreds = 0;
    while ( diff > 0 ) {
        if ( (diff - 100.0) >= 0.0 ) {
            diff -= 100.0;
            ++hundreds;
        }

        else if ( (diff - 50.0) >= 0.0 ) {
            diff -= 50.0;
            ++fifties;
        }

        else if ( (diff - 20.0) >= 0.0 ) {
            diff -= 20.0;
            ++twenties;
        }

        else if ( (diff - 10.0) >= 0.0 ) {
            diff -= 10.0;
            ++tens;
        }

        else if ( (diff - 5.0) >= 0.0 ) {
            diff -= 5.0;
            ++fives;
        }

        else if ( (diff - 1.0) >= 0.0 ) {
            diff -= 1.0;
            ++ones;
        }

        else if ( (diff - .25) >= 0.0 ) {
            diff -= .25;
            ++quarters;
        }

        else if ( (diff - .10) >= 0.0 ) {
            diff -= .10;
            ++dimes;
        }

        else if ( (diff - .05) >= 0.0 ) {
            diff -= .05;
            ++nickels;
        }

        else if ( (diff - .01) >= 0.0 ) {
            diff -= .01;
            ++pennies;
        }

        else {
            cerr << "This should never be printed." << endl;
            return;
        }
    }

    cout << "Your change is: " << endl;
    if ( hundreds > 0 ) {
        cout << "hundreds: " << hundreds << endl;
    }

    if ( fifties > 0 ) {
        cout << "fifties: " << fifties << endl;
    }

    if ( twenties > 0 ) {
        cout << "twenties: " << twenties << endl;
    }

    if ( tens > 0 ) {
        cout << "tens: " << tens << endl;
    }

    if ( fives > 0 ) {
        cout << "fives: " << fives << endl;
    }

    if ( ones > 0 ) {
        cout << "ones: " << ones << endl;
    }

    if ( quarters > 0 ) {
        cout << "quarters: " << quarters << endl;
    }

    if ( dimes > 0 ) {
        cout << "dimes: " << dimes << endl;
    }

    if ( nickels > 0 ) {
        cout << "nickels: " << nickels << endl;
    }

    if ( pennies > 0 ) {
        cout << "pennies: " << pennies << endl;
    }
}
