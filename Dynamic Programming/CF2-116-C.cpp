//
// Created by orabi on 3/17/2025.
//
#include <bits/stdc++.h>
using namespace std ;





int main() {
	string s ;
	cin >> s ;

	int lower = 0 ;
	int change = 0 ;
	for(int i = 0 ; i < s.size() ; i++) {
		if(s[i] >= 'a') {
			lower++;
		}else {
			if(lower > 0) {
				//this means that we facing upper after lower so we need to change it to lower
				lower-- ;
				change++;
			}
		}
	}
	cout << change << endl;
}