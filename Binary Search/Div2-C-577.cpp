//
// Created by orabi on 3/4/2025.
//
// created by MoniirMo
#include <bits/stdc++.h>
using namespace std;


int n , k ;
vector<long long>input;

bool ok(long long mid) {

		long long counter = 0 ;
		for(int i = n/2 ; i < n ; i++) {
			if(mid > input[i])
				counter+= (mid - input[i]);
			if(counter > k) return false ;
		}
	return counter <= k ;

}



int main() {
	cin >> n >> k ;

	for(int i = 0 ; i < n ; i++) {
		long long x ;
		cin >> x ;
		input.push_back(x);
	};
	sort(input.begin(),input.end());

	//we should keep getting the first >= value to the median and keep removing from k
	long long start = 1 ;
	long long end = 2e9+1 ;
	long long ans = 0 ;
	while(start <= end) {
		long long mid = start + ((end-start) / 2) ;
		if(ok(mid)) {
			start = mid + 1 ;
			ans = mid ;
		}else {
			end = mid - 1 ;
		}
	}
	cout << ans << endl;
}
