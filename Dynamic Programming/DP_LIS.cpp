//
// Created by orabi on 12/7/2024.
//
#include <bits/stdc++.h>
using namespace std ;


const int INF = INT_MAX ;

int main() {
    //first we will take the input size and input data
    int sz ;
    cin >> sz ;

    vector<int>input(sz);
    for(int i = 0 ; i < sz ; i++)
        cin >> input[i] ;
    vector<int>dp(sz+1,INF);
    dp[0] = -INF ;

    vector<int>dp_pos(sz+1,0);
    vector<int>p(sz,0);

    for(int i = 0 ; i < sz ; i++) {
        //you are looping for each element in the input array
        //you need to find the element
        int l_idx = upper_bound(dp.begin(), dp.end(), input[i]) - dp.begin() ;
        if(dp[l_idx-1] < input[i] && input[i] < dp[l_idx]) {
            dp[l_idx] = input[i] ;
            p[i] = dp_pos[l_idx] ;
            dp_pos[l_idx] = i ;
            //we are storing the index of the tail of the most optimal increasing subsequence of length i 
        }
    }
    int ans = -INF ;
    for(int i = 0 ; i <= sz ; i++) {
        if(dp[i] < INF)
            ans = i ;
    }
    cout << ans ;
    //what if we want to retrieve the sequence
    /*
     for each position
     */
}