//
// Created by orabi on 11/27/2024.
//

#include <bits/stdc++.h>

using namespace  std ;
int num_coin;
vector<int>coin_val(num_coin,0);
long long dp[1000005] ;
const int MOD = 1e9+7 ;

int main() {

    //trying to solve it using iterative dp

    cin >> num_coin ;

    int target ;
    cin >> target ;

    for(int i = 0 ; i < num_coin ;i++) {
        int holder ;
        cin >> holder ;
        coin_val.push_back(holder);
    }


    dp[0] = 1 ;
    for(int i = 0 ; i < num_coin ; i++) {
        for(int j = coin_val[i] ; j <= target ; j++) {
            if(j - coin_val[i] >= 0) {
                dp[j] += dp[j-coin_val[i]] ;
                dp[j] %= MOD ;
            }
        }
    }
    cout << dp[target] ;

}