//
// Created by orabi on 11/24/2024.
//
#include <bits/stdc++.h>

using namespace  std ;
long long n ;
int input[6] = {1,2,3,4,5,6};
long long dp[1000005][6] ;
const long long MOD = 1e9+7 ;

long long solve(int sum, int index) {

    if(sum == 0)
        return 1 ;

    if(dp[sum][index] != -1)
        return dp[sum][index] ;

    long long ret = 0 ;
    for(int i = 0 ; i < 6 ; i++) {
        //for each sum we can get we will try every combination;
        if(sum - input[i] >= 0) {
            ret = ((ret + solve(sum-input[i] , i))%MOD);
        }
    }

    return dp[sum][index] = ret ;
}


int main() {
    cin >> n ;

    for(int i = 0 ; i < 1000005 ; i++) {
        for(int j = 0 ; j < 6 ; j++) {
            dp[i][j] = -1 ;
        }
    }

    cout << (solve(n,0) % MOD) << endl;

}