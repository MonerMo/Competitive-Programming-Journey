//
// Created by orabi on 11/28/2024.
//

#include <bits/stdc++.h>

using namespace std ;

int main() {
    int n ;
    cin >> n ;
    vector<int>input(n);
    for(int i = 0 ; i < n ; i++) cin >> input[i] ;

    long long local_max = input[0] ;
    long long global_max = input[0] ;
    for(int i = 1 ; i < n ; i++) {
        local_max = max(static_cast<long long>(input[i]) , static_cast<long long>(input[i] + local_max));
        if(local_max > global_max) global_max = local_max ;
    }
    cout << global_max << endl;
}