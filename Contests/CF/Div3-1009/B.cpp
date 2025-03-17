//
// Created by orabi on 3/11/2025.
//
#include <bits/stdc++.h>
using namespace std ;
int main() {
	int t ;
	cin >> t ;
	while(t--) {
		int n ; //size of sequence
		cin >> n ;


		long long ans = 0 ;
		for(int i = 0 ; i < n ; i++) {
			int holder ;
			cin >> holder ;
			ans += holder ;
		}
		ans -= (n-1) ; //for the differences
		cout << ans << endl;
	}
}