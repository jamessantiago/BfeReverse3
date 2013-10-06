// BfeReverse3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BfeReverse3.h"

using namespace std;

/* This function return the gcd of a and b followed by
    the pair x and y of equation ax + by = gcd(a,b)
	function from:
	http://comeoncodeon.wordpress.com/2011/10/09/modular-multiplicative-inverse/
	*/
pair<int, int> extendedEuclid(signed long long a, signed long long b) {
    signed long long x = 1, y = 0,
		xLast = 0, yLast = 1,
		q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(xLast, yLast);
}
 

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	pair<int, int> e = extendedEuclid(2813506931, -signed long long(3237618779));
	
	printf("Key found   %08X:%08X \n", e.first, e.second);
	return 0;
}
