//
// Created by orabi on 3/7/2025.
//
#include <bits/stdc++.h>
using namespace std ;

int cond = 0 ;
void primeCount(int input) {
	vector<int>flag(input+2 , 1);

	flag[0] = flag[1] = 1 ;

	for(long long i = 2 ; i * i <= input + 1 ; i++) {
		if(flag[i] == 1) {
			for(long long j = i * i ; j <= input + 1 ; j+=i) {
				cond = 1 ;
				flag[j] = 2 ;
			}
		}
	}
	if(cond)
		cout << 2 << endl;
	else
		cout << 1 << endl;
	for(int i = 2 ; i <= input+1 ; i++) cout << flag[i] << " " ;
}

int main() {
	int n ;
	cin >> n ;
	primeCount(n);
}