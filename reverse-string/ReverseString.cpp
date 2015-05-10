#include <iostream>
using namespace std;

string reverseString( char* str );

int main() {
    char str[100];
    cout << "Enter a string to reverse:" << endl;
    cin.getline(str, 100);
    cout << "Your string in reverse is: " << reverseString( str ) << endl;
    while ( true ) {
        cout << "\nPress 'q' to quit or another string to reverse:" << endl;
        cin.getline(str, 100);
        if ( str[0] == 'q' ) {
            break;
        }
        cout << "Your string in reverse is: " << reverseString( str ) << endl;
    }
}

string reverseString( char* str ) {
    char* frontPtr = &str[0];
    char* endPtr = &str[0];
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
    

