//
// Created by orabi on 3/5/2025.
//
//created by MoniirMo
#include <bits/stdc++.h>
using namespace std ;

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

	long long counter = 0 ;
	for(long long idx = 2 ; idx <= input ; idx++) {
		if(flag[idx]) Values.push_back(idx);
	}
	return Values ;
}



int main() {

	int n , k ;
	cin >> n >> k ;
	vector<long long> holder = primeCountValues(n);

	//in all cases we will have 2 3 7 and goes on so start with index 2
	int counter = 0;
	for(int i = 2 ; i < holder.size() ; i++) {
		for(int j = 0 ; j < i ; j++) {
			if(holder[i] == holder[j] + holder[j+1] + 1) counter++;
		}
	}

	if(counter == k || k == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

}
