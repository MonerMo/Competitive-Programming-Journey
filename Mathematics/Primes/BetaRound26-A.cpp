//
// Created by orabi on 3/6/2025.
//
#include <bits/stdc++.h>
using namespace std ;

set<long long>uniquePrimeFactors(long long input) {
	set<long long> primes ;
	for(long long i = 2 ; i * i <= input ; i++) {
		while(input % i == 0)
			primes.insert(i) , input/=i ;
	}

	if(input > 1) primes.insert(input);
	return primes ;
}

int main() {
	long long n ;
	cin >> n ;
	int counter = 0 ;

	for(long long i = 1 ; i <= n ;i++) {
		//for each number from 1 to n check if it has 2 exactly 2 distinctive prime factors
		set<long long> holder = uniquePrimeFactors(i) ;
		if(holder.size() == 2) counter++ ;
	}
	cout << counter << endl;

}