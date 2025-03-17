//
// Created by orabi on 12/9/2024.
//
#include <bits/stdc++.h>
using namespace std ;

int main() {

    int n ;
    cin >> n ;
    for(int i = 2 ; i*i <= n ; i++) {
        if(n%i==0) {
            cout << "NOT PRIME" ;
            return 0 ;
        }
    }
    cout << "PRIME" ;
    return 0 ;
}