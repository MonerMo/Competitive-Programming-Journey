//
// Created by orabi on 11/29/2024.
//
#include<bits/stdc++.h>
using namespace std ;

int n ;

//vector<vector<bool>>dp(n+1, vector<bool>(MAX_VAL+1,false));
bool dp[101][100005] ;

int main() {
    cin >> n ;
    const int MAX_VAL = n * 1000 ;
    vector<int>input(n+1,0);
    for(int i = 1 ; i <= n ; i++) {
        cin >> input[i] ;
    }


    for(int i = 0 ; i <= n ; i++)
        for(int j = 0 ; j <= MAX_VAL ; j++)
            dp[i][j] = false ;

    //now we need to outer loop over all the coins
    dp[0][0] = true ;
    for(int coin_idx = 1 ; coin_idx <= n ; coin_idx++) {
        for(int pos_sum = 0 ; pos_sum <= MAX_VAL ; pos_sum++) {
            //we can say that at specified pos_sum is possible if it is possible by coins i-1
            //or by taking the current coin from the pos_sum and the remaining satisfied already before.
            dp[coin_idx][pos_sum] = dp[coin_idx-1][pos_sum] ; // if it's possible by coins i-1
            int remaining = pos_sum - input[coin_idx] ;
            if(remaining >= 0 && dp[coin_idx-1][remaining])
                dp[coin_idx][pos_sum] = true ; // if it's not possible by coins i-1 we check it it's valid after taking current coin
        }
    }
    dp[n][0] = false ;

    vector<int>possible_sums ;
    for(int i = 0 ; i <= MAX_VAL ; i++) {
        if(dp[n][i]) possible_sums.push_back(i);
    }

    cout << possible_sums.size() << '\n';
    for(auto x : possible_sums) cout << x << " " ;
    cout << '\n';



}