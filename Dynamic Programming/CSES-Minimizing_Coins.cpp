//
// Created by orabi on 11/27/2024.
//

#include <bits/stdc++.h>

using namespace  std ;
int n ;
int desired ;
vector<int> input(n);

int dp[1000005][101] ;

const int oo = 1e6+2 ;

int solve(int sum, int index) {

    if(sum == 0)
        return 0 ;


    if(dp[sum][index] != -1)
        return dp[sum][index] ;

    int ret = INT32_MAX - 100 ;
    for(int i = 0 ; i < n ; i++) {
        if(sum-input[i] >= 0) {
            ret = min(ret , solve(sum-input[i],i)+1) ;
        }
    }

    return dp[sum][index] = ret ;

}


int main() {
    cin >> n ;
    cin >> desired ;

    for(int i = 0 ; i < n ; i++) {
        int holder ;
        cin >> holder ;
        input.push_back(holder) ;
    }



    for(int i = 0 ; i < 1000005 ; i++) {
        for(int j = 0 ; j < 101 ; j++) {
            dp[i][j] = -1 ;
            if(input[j] == 1) {
                dp[i][j] = i ;
            }
        }
    }



    int holder = solve(desired,0) ;
    if(holder == 2147483547)
        cout << -1 << endl;
    else
        cout << holder ;

}