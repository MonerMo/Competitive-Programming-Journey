//
// Created on 12/15/2024.
//
//created by MoniirMo
#include <bits/stdc++.h>
using namespace std ;

int main() {
    int t ;
    cin >> t ;
    int counter = 0  ;
    while(t--) {
        int n ;
        cin >> n ;
        for(int i = 1 ; i <= 100 ; i++) {
            for(int j = 1  ; j <= 100 ; j++) {
                if(i+j == n) counter++;
            }
        }
        cout << counter << endl;
        counter = 0 ;
    }
}
