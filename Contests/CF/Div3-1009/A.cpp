//
// Created by orabi on 3/11/2025.
//
#include <bits/stdc++.h>

using namespace std ;

int main() {
	int t ;
	cin >> t ;
	while(t--) {
		int l , r , d , u ;
		cin >> l >> r >> d >> u ;
		if(l == r && l == u && l == d)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}