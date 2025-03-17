
#include <bits/stdc++.h>

using namespace  std ;

int main() {
    vector<int>holder ;
	int n ;
	cin >> n ;
	for(int i = 0 ; i < n ; i++){
		int input ;
		cin >> input;
		holder.push_back(input);
	}

	sort(holder.begin() , holder.end());
	for(auto x : holder) cout << x << " " ;
	cout << endl ;
}
