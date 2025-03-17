// created by MoniirMo
#include <bits/stdc++.h>
using namespace std;

int main() {
	int sz ;
	cin >> sz ;

	string str ;
	cin >> str ;
	vector<int> freq[26] ;
	int calc ;
	for(int i = 0 ; i < sz ; i++) {
		freq[str[i] - 'a'].push_back(i+1) ;
	}

	int tt ;
	cin >> tt ;
	string holder ;

	while(tt--) {
		int cur[26] = {0} ;
		cin >> holder ;
		int ans = -1000 ;
		for(int i = 0 ; i < holder.size() ; i++) {
			//for each letter
			++cur[holder[i] - 'a'] ;
			ans = max(ans , freq[holder[i] - 'a' ][cur[holder[i] - 'a'] - 1]) ;
		}
		cout << ans << endl;
	}
}
