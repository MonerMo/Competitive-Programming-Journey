 // created by MoniirMo
#include <bits/stdc++.h>
using namespace std;

int main() {
	int tt;
	cin >> tt ;
	while(tt--) {
		int n , k ;
		cin >> n >> k ;
		int shift =  (k-1) / (n-1)  ;
		cout << shift + k << endl;
	}

}
