#include <iostream>
#include <string>
#include "Luhn.hpp"
using namespace std;

const int ASCII_ZERO = (int) '0';
const int ASCII_NINE = (int) '9';

int main() {
    string cardNumber;
    cout << "Enter credit card number." << endl;
    cin >> cardNumber;

    bool valid = isValid( cardNumber );
    if ( valid ) {
        string typeOfCard = getTypeOfCard( cardNumber );
        cout << "Your " << typeOfCard << " is valid!" << endl;
    } else {
        cout << "Your card is invalid!" << endl;
    }
    return EXIT_SUCCESS;
}

bool isValid( string card ) {
    int cardSize = card.size();
    cout << cardSize << endl;

    if ( cardSize < 14 || cardSize > 16 ) {
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
    int checkValue = cardNum[reducedCardSize] - '0'; // last digit
    int totalValue;

    cardNum.pop_back();

    cardNum = reverseString( cardNum );
    cardNum = multiplyOdds( cardNum );
    totalValue = addAllValues( cardNum );
    if ( totalValue % 10 == checkValue ) {
        return true;
    }

    return false; //TODO: delete this
}

int addAllValues( string str ) {
    int total = 0;
    for ( int i = 0 ; i < str.size() ; ++i ) {
        total += str[i] - '0';
    }
    return total;
}

string multiplyOdds( string str ) {
    string multOddsStr;
    for ( int i = 1 ; i <= str.size() ; ++i ) {
        int strVal = str[i-1] - '0';
        if ( i % 2 == 1 ) {
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
    return multOddsStr;
}

string getTypeOfCard( string cardNumber ) {
    char firstNum = cardNumber[0];
    char secondNum = cardNumber[1];
    if ( firstNum == '4' ) {
        return "Visa";
    } else if ( firstNum == '3' ) {
        if ( secondNum == '4' || secondNum == '7' ) {
            return "American Express";
        }
    } else if ( firstNum == '5' ) {
        if ( secondNum >= '1' && secondNum <= '5' ) {
            return "MasterCard";
        }
    }

    return "Credit Card";
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
