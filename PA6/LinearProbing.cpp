#include "LinearProbing.h"

using namespace std;

bool isPrime(int n) {
    if( n == 2 || n == 3 )
        return true;

    if( n == 1 || n % 2 == 0 )
        return false;

    for( int i = 3; i * i <= n; i += 2 )
        if( n % i == 0 )
            return false;

    return true;
}

int nextPrime(int n) {
    if( n % 2 == 0 )
        ++n;

    for( ; !isPrime( n ); n += 2 )
        ;

    return n;
}