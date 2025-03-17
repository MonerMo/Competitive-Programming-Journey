//
// Created by orabi on 12/9/2024.
//
#include <bits/stdc++.h>
using namespace std ;
vector<int>factors;

int main() {

    int n ;
    cin >> n ;
    int holder = n ;
    for(int i = 2 ; i*i <= holder ; i++) {
        if(n%i==0) {
            while(n%i==0) {
                factors.push_back(i);
                n/=i ;
            }
        }
    }
    if(factors.size() == 0) {
        cout <<"PRIME, NO FACTORS." ;
    }else {
        cout << "PRIME" << endl;
        for(auto x : factors) cout << x << " " ;
    }
}