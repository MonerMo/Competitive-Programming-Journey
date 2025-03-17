//
// Created by orabi on 3/10/2025.
//
#include <bits/stdc++.h>

using namespace std ;

bool isPrime(int input) {
	if(input == 2) return true ;

	if(input < 2 || input % 2 == 0) return false ;
	for(int i = 3 ; i * i <= input ; i+=2) {
		if(input % i == 0) return false ;
	}
	return true ;
}


vector<int> primeCountValues(int input) {
	vector<bool>flag(input+1 , true);
	vector<int> Values ;

	flag[0] = flag[1] = false ;

	for(int i = 2 ; i * i <= input ; i++) {
		if(flag[i]) {
			for(long long j = i * i ; j <= input ; j+=i) {
				flag[j] = false ;
			}
		}
	}

	for(int idx = 2 ; idx <= input ; idx++) {
		if(flag[idx]) Values.push_back(idx);
	}
	return Values ;
}

int main() {
	int n ;
	cin >> n ;
	int first_prime = n ;



	while(!isPrime(first_prime)) {
		first_prime-- ;
	}

	if(first_prime == n) {
		cout << 1 << endl;
		cout << n ;
		return 0 ;
	}

	//now we will generate first primes under 300
	vector<int>holder = primeCountValues(300);
	int second , third ;
	for(int i = 0 ; i < holder.size() ; i++) {
		second = holder[i] , third = n - first_prime - second ;
		if(isPrime(third)) {
			break;
		}else if(third == 0) {
			cout << 2 << endl;
			cout << first_prime << " " << second << endl;
			return 0;
		}else {
			continue ;
		}
	}

	cout << 3 << endl;
	cout << third << " " << second << " " << first_prime ;
	return 0;


}