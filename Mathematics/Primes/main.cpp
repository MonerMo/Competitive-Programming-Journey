#include <iostream>
//#include "Prime_Calc.h"
using namespace std ;

long long eea(long long a , long long b , long long &x , long long &y) {
	if(b == 0) {
		x = 1 , y = 0;
		return a ;
	}

	//swap a with a%b and swap x with y
	long long g = eea(b , a % b , y , x) ;
	y = y - (a/b) * x ; //here newest x will already equal past y and
	//y will need to be calculated from the newest x

	//return gcd = g ;
	return g ;
}


int main() {
    //let a = 2 , p = 3
    // 2^1 + 2^2 + 2^3 = 2 + 4 + 8 = 14
	long long x , y ;
    cout << eea(2, -5 , x , y) << endl;
    cout << x << " " << y << endl;
    return 0;
}
