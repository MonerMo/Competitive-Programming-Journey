//
// Created on 12/15/2024.
//
//created by MoniirMo
#include <bits/stdc++.h>
using namespace std ;

int main() {
    int t;
    cin >> t ;
    while(t--) {
        long long m , a , b,  c ;
        cin >> m >> a >> b >> c  ;
        //first we want to take as much as we can from a and b and remaining will take from c
        long long rem = 0 ;
        long long ans = 0 ;
        if(a >= m) {
            ans += m ; //took the first row
        }else if(a < m) {
            ans += a ;
            rem += m - a ;
        }
        if(b >= m) {
            ans += m ; //took the first row
        }else if(b < m) {
            ans += b ;
            rem += m - b ;
        }

        if(rem >= c) {
            ans += c ; //took the first row
        }else if(rem < c) {
            ans += rem ;
        }

        cout << ans << endl;

    }
}
