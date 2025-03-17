//
// Created by orabi on 11/27/2024.
//
#include <bits/stdc++.h>

using namespace std ;

int coins[6] = {1,2,3,4,5,6} ;
long long dp[1000005] ;
long long const MOD = 1e9+7 ;

int main() {
    int sum ;
    cin >> sum;
    for(int i = 0 ; i < 1000005 ; i++) dp[i] = 0 ;
    dp[0] = 1 ;
    dp[1] = 1 ;

    for(int i = 2 ; i <= sum ; i++) {
        for(int j = 0 ; j < 6 ; j++) {
            dp[i] = (dp[i] % MOD) + (dp[i - coins[j]]%MOD) ;
        }
    }
    cout << ( dp[sum] % MOD ) ;

}