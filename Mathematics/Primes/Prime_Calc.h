//
// Created by orabi on 3/5/2025.
//

#ifndef PRIME_CALC_H
#define PRIME_CALC_H
#include <bits/stdc++.h>
using namespace std ;

bool isPrime(long long input) {
	if(input == 2) return true ;

	if(input < 2 || input % 2 == 0) return true ;
	for(long long i = 3 ; i * i <= input ; i+=2) {
		if(input % i == 0) return false ;
	}
	return true ;
}


long long primeCount(long long input) {
	vector<bool>flag(input+1 , true);

	flag[0] = flag[1] = false ;

	for(long long i = 2 ; i * i <= input ; i++) {
		if(flag[i]) {
			for(long long j = i * i ; j <= input ; j+=i) {
				flag[j] = false ;
			}
		}
	}

	long long counter = 0 ;
	for(long long idx = 2 ; idx <= input ; idx++) {
		if(flag[idx]) counter++;
	}
	return counter ;
}


vector<long long> primeCountValues(long long input) {
	vector<bool>flag(input+1 , true);
	vector<long long> Values ;

	flag[0] = flag[1] = false ;

	for(long long i = 2 ; i * i <= input ; i++) {
		if(flag[i]) {
			for(long long j = i * i ; j <= input ; j+=i) {
				flag[j] = false ;
			}
		}
	}

	for(long long idx = 2 ; idx <= input ; idx++) {
		if(flag[idx]) Values.push_back(idx);
	}
	return Values ;
}



vector<long long> Divisors(long long input) {
	vector<long long>holder ;
	//don't use it with zero and in case of 1 return 1
	if(input == 1 || input == 0) {
		holder.push_back(1);
		return holder ;
	}

	long long i = 1 ;
	for(; i * i < input ; i++) {
		if(input % i == 0) {
			holder.push_back(i) , holder.push_back(input/i);
		}
	}

	if(i * i == input) holder.push_back(i);
	return holder ;
}


vector<long long> primeFactors(long long input) {
	vector<long long> primes ;
	for(long long i = 2 ; i * i <= input ; i++) {
		while(input % i == 0)
			primes.push_back(i) , input/=i ;
	}

	if(input > 1) primes.push_back(input);
	return primes ;
}

set<long long>uniquePrimeFactors(long long input) {
	set<long long> primes ;
	for(long long i = 2 ; i * i <= input ; i++) {
		while(input % i == 0)
			primes.insert(i) , input/=i ;
	}

	if(input > 1) primes.insert(input);
	return primes ;
}


vector<long long> SPF(long long input) {
	vector<long long>spf(input+1 , 1);
	spf[0] = 0 ;

	for(long long i = 2 ; i  <= input ; i++) {
		if(spf[i] == 1) {
			spf[i] = i ;
			for(long long j = i * i ; j <= input ; j+=i) {
				spf[j] = i ;
			}
		}
	}
	return spf ;
}


void primeFactorsQuery(vector<long long> &spf , long long input) {
	while(input != 1) {
		cout << spf[input] << " " ;
		input /= spf[input] ;
	}
}


long long numOfPrimesInFactorial(long long factorial, long long prime) { //O(log(n) base p)
	long long counter = 0;
	for(long long i = prime ; i <= factorial ; i*=prime) {
		counter += ( factorial / i ) ;
	}
	return counter ;
}

//take care to pass the smaller value to b and the bigger value to a
int gcd(int a , int b) {
	if(b==0)
		return a ;
	return gcd(b , a%b);
}

long long pow(long long a , long long b) {
	if(b == 0) return 1 ;
	long long intermediate = pow(a , b/2) ;
	intermediate *= intermediate ;

	if(b%2 == 1) intermediate *= a ;
	return intermediate ;
}

long long powSeries(long long a , long long p) {
	if(p == 0) return 1 ;

	if(p % 2 == 1)
		return a * (1 + powSeries(a , p-1)) ;

	long long half = powSeries(a , p/2);
	return half * (1 + half - powSeries(a, p/2 - 1)) ;
}

//already from the past we pass a & b and we get gcd back
//this will solve a and y only if (ax + by = g = gcd(a,b)) ;
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



#endif //PRIME_CALC_H
