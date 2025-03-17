//
// Created by orabi on 3/8/2025.
//
#include <bits/stdc++.h>
using namespace std ;


int arr[100001] ;
set<int> prime[100001] ;

set<int>uniquePrimeFactors(int input) {
	set<int> primes ;
	for(int i = 2 ; i * i <= input ; i++) {
		while(input % i == 0)
			primes.insert(i) , input/=i ;
	}

	if(input > 1) primes.insert(input);
	return primes ;
}

vector<int> SPF(int input) {
	vector<int>spf(input+1 , 1);
	spf[0] = 0 ;

	for(int i = 2 ; i  <= input ; i++) {
		if(spf[i] == 1) {
			spf[i] = i ;
			for(int j = i * i ; j <= input ; j+=i) {
				spf[j] = i ;
			}
		}
	}
	return spf ;
}



int main() {
	int n , m ;
	cin >> n >> m ;
	prime[1].insert(1);

	//we should make an array with spf of each collider , and an array of vectors that for each spf in the array we add
	//the colliders that already added from before.

	while(m--) {

		char sign ;
		int input ;
		cin >> sign >> input ;

		//first we compute the prime factors for each number
		if(prime[input].empty())
			prime[input] = uniquePrimeFactors(input);

		if(sign == '+') {
			//after we calculated , to tell if the number not been added before we should check for all prime
			bool check = false ;
			bool same = false ;
			int idx_false = 0 ;
			for(auto it = prime[input].begin() ; it != prime[input].end() ; ++it ) {
				if(arr[*it]== 0) {
					check = true ;
				}else {
					idx_false = arr[*it] ;
					if(arr[*it] == input) same = true ;
					check = false ;
					break;
				}
			}

			if(check) {
				//this means that the element hadn't been added before , then add it to all it's factors
				for(auto it = prime[input].begin() ; it != prime[input].end() ; ++it) {
					arr[*it] = input;
				}
				cout << "Success" << endl;
			}else {
				//this means that the number have a conflict with some number or maybe already added
				if(same == true) {
					cout << "Already on" << endl;
				}else {
					cout << "Conflict with " << idx_false << endl;
				}
			}
		}else {
			//after we calculated , to tell if the number not been added before we should check for all prime
			bool check = false ;
			for(auto it = prime[input].begin() ; it != prime[input].end() ; ++it ) {
				if(arr[*it]!= input) {
					check = true ;
				}else {
					check = false ;
					break;
				}
			}

			//if check equal true this means it is not added before
			if(check) {
				cout << "Already off" << endl;
			}else {
				for(auto it = prime[input].begin() ; it != prime[input].end() ; ++it) {
					arr[*it] = 0;
				}
				cout << "Success" << endl;
			}
		}
	}
}