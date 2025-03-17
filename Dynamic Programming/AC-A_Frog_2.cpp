//
// Created by orabi on 11/24/2024.
//
#include <bits/stdc++.h>

using namespace std ;
int input[100001] ;
int n ;
int k ;
vector<int>dp(100001,-1);


int solve(int pos) {

    if(pos == n-1)
        return 0 ;

    if(dp[pos] != -1)
        return dp[pos] ;

    int first = solve(pos +1) + abs(input[pos] - input[pos+1]);
    for(int i = 2 ; i <= k ; i++) {
        if(pos+i<n)
            first = min(first, solve(pos+i) + abs(input[pos] - input[pos+i])) ;
    }
    return dp[pos] = first ;
}


int main() {

    cin >> n >> k ;
    for(int i = 0 ; i < n ; i++) {
        cin >> input[i] ;
    }
    cout << solve(0) ;

}