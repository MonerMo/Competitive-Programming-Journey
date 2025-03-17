//
// Created on 12/22/2024.
//
//created by MoniirMo
#include <bits/stdc++.h>
using namespace std ;

int main() {
    int t ;
    cin >> t ;
    while(t--) {
        long long n , a , b , c ;
        cin >> n >> a >> b >> c ;
        // day 1 and day 2
        long long day123 = a + b + c ;
        //if n > day123 ;
        long long cnt = 0 ;
        if(n/day123) {
            cnt = 3 * (n/day123) ;
            n %= day123 ;
        }

        if(n > 0){
             if(n > 0 ) {
                 n -= a ;
                 cnt++ ;
             }
            if(n > 0) {
                n -= b ;
                cnt++ ;
            }
            if(n > 0) {
                n -= c ;
                cnt++ ;
            }
        }
        cout << cnt << endl;
    }

}
