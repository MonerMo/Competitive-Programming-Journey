//
// Created by orabi on 11/23/2024.
//
#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
ll s , k ;
ll mem[21][101] ;
ll solve(ll cur_sum, ll index) {

    if(index == k) {
        if(cur_sum == 0)
            return 1 ;
        return 0 ;
    }

    if(cur_sum == 0)
        return 0;

    //i should have a small value of ret
    ll &ret = mem[index][cur_sum] ;
    if(ret != -1) {
        return ret ;
    }
    ret = 0 ;

    //we will loop from value = 1 to < s
    for(int i = 1 ; i <= cur_sum ; i++) {
        ll sol = i * solve(cur_sum-i, index+1);
        ret = max(sol,ret) ;
    }
    return ret ;
}


int main() {

    cin >> s >> k ;
    for(int i = 0 ; i < 21 ; i++) {
        for(int j = 0 ; j < 101 ; j++) {
            mem[i][j] = -1 ;
        }
    }
    cout << solve(s,0) ;

}