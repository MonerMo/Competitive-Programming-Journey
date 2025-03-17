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
    for(int i = 1 ; i <= target ; i++) {
        for(int j = 0 ; j < num_coin ; j++) {
            if(i - coin_val[j] >= 0) {
                dp[i] += dp[i-coin_val[j]] ;
                dp[i] %= MOD ;
            }
        }
    }
    cout << dp[target] ;

}