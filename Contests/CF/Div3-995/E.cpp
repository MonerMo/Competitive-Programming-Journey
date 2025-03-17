//
// Created on 12/22/2024.
//
//created by MoniirMo
#include <bits/stdc++.h>
using namespace std ;

int a[101] ;
int b[101] ;


int main() {
    int t ;
    cin >> t ;
    while(t--) {
        int n;
        cin >> n ;


        int holder ;
        for(int i = 0 ; i < n ; i++) cin >> a[i] ;
        for(int i = 0 ; i < n ; i++) cin >> b[i] ;

        int sum = 0 ;
        for(int i = 0 ; i < n - 1 ; i++)
            sum += max(0 , a[i] - b[i+1]);
        sum += a[n - 1] ;
        cout << sum << endl;

    }

}
