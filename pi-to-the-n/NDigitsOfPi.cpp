#include <iostream>
#include <fstream>
using namespace std;
const int EXPECTED_ARGS = 2;
int convertToInt( char* cInput );

int main( int argc, char** argv) {
    ifstream in;

    if ( argc != EXPECTED_ARGS ) {
        cerr << "Missing number argument." << endl;
        cerr << "Example:   ./getpi 5" << endl;
        return EXIT_FAILURE;
    }

    char* nthDigit = argv[1]; //TODO: check if this is accepted
    int result = convertToInt(nthDigit);
    cout << "Converted number is " << result << endl;

    in.open( "pi.txt" );

    for ( int i = 0 ; i < 15 ; ++i ) {
        cout << in.get() - '0' << endl;
        if (! in.good() ) {
            break;
        }
    }

    in.close();
    return EXIT_SUCCESS;
}

int convertToInt( char* cInput) {
    char* ptr;
    int ptrWalkCount = 0;
    int result = 0;
    while ( ptr != NULL ) {
        ptr = &cInput[ptrWalkCount];
        ++ptrWalkCount;
    }
    --ptrWalkCount;

    for ( int i = 0 ; i < ptrWalkCount ; ++i ) {
        char currentChar = cInput[ptrWalkCount];
        int currentNum = (int) (currentChar - '0');
        result += currentNum * (10 * i);
    }

    return result;
}
