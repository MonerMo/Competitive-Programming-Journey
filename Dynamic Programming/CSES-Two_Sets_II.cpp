//
// Created by orabi on 11/30/2024.
//

#include<bits/stdc++.h>
using namespace std ;
int dp[501][125251] ;
int const MOD = 1e9+7 ;
int main() {
    int n ;
    cin >> n ;

    //because we have n <= 500
    //now we will calculate the sum
    int sum = (n*(n+1)) / 2 ; //we use this technique because we are sure it won't overflow
    //we want to check if the sum can be divided or not
    if(sum%2 == 0) {
        //we will go through all possible coins and all possible sums
        dp[0][0] = 1 ;
        //for(int i = 0 ; i <= n ; i++) dp[i][0] = 1 ;
        sum /= 2 ;
        for(int coin_val = 1 ; coin_val <= n ; coin_val++) {
            for(int target = 1 ; target <= sum ; target++) {
                //first we assume that the sum has been done by a coin less than the current
                dp[coin_val][target] = dp[coin_val-1][target] ;
                //but also we need to add the possibility if it can be done using the current coin
                int remaining = target - coin_val ;
                if(remaining >= 0 && dp[coin_val-1][remaining]) {
                    dp[coin_val][target] += 1*dp[coin_val-1][remaining] ;
                    dp[coin_val][target] %= MOD ;
                }
            }
        }
        cout << dp[n][sum] << endl;
    }else {
        cout << 0 ;
    }
}