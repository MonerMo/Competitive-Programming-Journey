//
// Created by orabi on 3/12/2025.
//
#include <bits/stdc++.h>
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
	long long n , m , a , k ;

	while(true) {
		cin >> n >> m >> a >> k ;
		if(n == 0 && m == 0 && k == 0 && a == 0) break;

		//here we will create c in the equation ax + by = c .
		long long c = n - k ;


		//first we need to check if we have a valid integer solution
		long long x0 , y0 ;
		long long g = eea(a, -m, x0 , y0);
		if(c%g != 0) {
			cout << "Impossible" << endl;
			continue ;
		}

		//check if the gcd < 0
		if(g < 0)
			x0 = -x0 , y0 = -y0 , g = -g ;

		/*
		 so general solution for x = x0 + [ K * (b / gcd(a,b)=g) ] and for y = y0 - [ K * (a / gcd(a,b)=g) ]
		so general solution for x = x0 + [ M * (b / gcd(a,b)=g) ] and for y = y0 - [ K * (A / gcd(a,b)=g) ]
		long long k_x = ceil((1-x0) * 1.0 / (m / g))
		long long k_y = ceil((0-y0) * 1.0 / (a / g))

		long long k = max(k_x , k_y)
		after that we apply it on k+a * x

		*/

		//if we continued here means that we have an integer solution


		//
		x0 = x0*(c/g);
		y0 = y0*(c/g) ;

		long long d = m/g;
		long long d1 = a/g ;

		if(y0 <= 0) {
			long long shift = (abs(y0)/d1)+1 ;
			y0+= d1*shift ;
		}else {
			long long shift = (y0-1)/ d1 ;
			y0 -= d1*shift ;
		}

		if(x0 <= 0){
			long long shift = (abs(x0)/d)+1;
			x0 += d*shift;
		}else{
			long long shift = (x0-1)/d;
			x0 -= d*shift;
		}

		//cout << x0 << " " << y0 << endl;
		cout << k+a*x0 << endl;
		//cout << n+m*y0 << endl;
	}

}
