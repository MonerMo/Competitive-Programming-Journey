#include <bits/stdc++.h>
using namespace std ;

int n ;
vector<int>input ;

const int MAX = 1e5+1 ;
int dp[MAX] ;


int solve(int index) {
	if(index == n-1 )
		return 0 ;

	if(dp[index] != -1)
		return dp[index] ;

	int choice1 = 2e9 ;
	int choice2 = 2e9 ;
	if(index + 1 < n)
		choice1 = abs(input[index] - input[index+1]) + solve(index + 1) ;

	if(index + 2 < n)
		choice2 = abs(input[index] - input[index+2]) + solve(index + 2);

	return dp[index] = min(choice1 , choice2);
}


int main() {
	cin >> n ;
	for(int i = 0 ; i < n ; i++) {
		int holder ;
		cin >> holder ;
		input.push_back(holder);
	}

	for(int i = 0 ; i < 1e5+1 ; i++) {
		dp[i] = -1 ;
	}

	cout << solve(0);
}
