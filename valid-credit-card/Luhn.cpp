#include <iostream>
#include <string>
using namespace std;

string reverseString( string str );
bool luhnsAlgo( string cardNum );
bool isValid( string card );
string multiplyOdds( string str );
int addAllValues( string str );

const int ASCII_ZERO = (int) '0';
const int ASCII_NINE = (int) '9';

int main() {
    string cardNumber;
    cout << "Enter credit card number." << endl;
    cin >> cardNumber;

    bool valid = isValid( cardNumber );

    return EXIT_SUCCESS;
}

bool isValid( string card ) {
    int cardSize = card.size();
    cout << cardSize << endl;

    cerr << "Original card: " << card << endl;

    if ( cardSize < 14 || cardSize > 15 ) {
        cerr << "Invalid card length." << endl;
        return false;
    }

    for ( int i = 0 ; i < cardSize ; ++i ) {
        int currentChar = (int) card.at(i);
        if ( currentChar < ASCII_ZERO || currentChar > ASCII_NINE ) {
            cerr << "Card contains invalid symbols." << endl;
            return false;
        }
    }

    
    return luhnsAlgo( card );
}

bool luhnsAlgo( string cardNum ) {
    int reducedCardSize = cardNum.size() - 1;
    int checkValue = (int) cardNum.at( reducedCardSize ); // last digit
    int totalValue;

    cardNum.pop_back();

    cardNum = reverseString( cardNum );
    cerr << "Reversed card minus last: " << cardNum << endl;
    cardNum = multiplyOdds( cardNum );
    cerr << "Multiplied odds is: " << cardNum << endl;

    totalValue = addAllValues( cardNum );
    cerr << "The total of all numbers is " << totalValue << endl;

    if ( totalValue % 10 == checkValue ) {
        cout << "Valid card!" << endl;
        return true;
    }

    cout << "Invalid Card!" << endl;
    return false; //TODO: delete this
}

int addAllValues( string str ) {
    int total = 0;
    for ( int i = 0 ; i < str.size()-1 ; ++i ) {
        total += str[i] - '0';
    }
    return total;
}

string multiplyOdds( string str ) {
    string multOddsStr;
    for ( int i = 0 ; i < str.size()-1 ; ++i ) {
        int strVal = str[i] - '0';
        if ( strVal % 2 == 1 ) {
            int doubleVal = strVal * 2;
            if ( doubleVal > 9 ) {
                multOddsStr.append( to_string( doubleVal - 9 ) );
            } else {
                multOddsStr.append( to_string( doubleVal ) );
            }
        } else {
            multOddsStr.append( to_string( strVal ) );
        }
    }
    cerr << "multOddsStr: " << multOddsStr << endl;
    return multOddsStr;
}

string reverseString( string str ) {
    char* endPtr = &str[0];
    char* frontPtr = &str[0];
    char temp;

    while ( *endPtr ) {
        ++endPtr;
    }
    --endPtr;

    while ( frontPtr < endPtr ) {
        temp = *frontPtr;
        *frontPtr = *endPtr;
        *endPtr = temp;
        ++frontPtr;
        --endPtr;
    }
    return str;
}
