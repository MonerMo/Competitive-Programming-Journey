//
// Created by orabi on 2/14/2024.
//
#include <bits/stdc++.h>

using namespace std ;

int main(){

    int n , q ;
    cin >> n >> q ;

    vector<unsigned long long>pre(n+1,0);

    unsigned int holder = 0;
    bool zero_index = true ;
    for(int i = 1 ; i <= n ; i++){
        cin >> holder ;
        pre[i] = pre[i-1] + holder ;
    }

    while(q--){
        int l = 0 , r = 0 ;
        cin >> l >> r ;
        cout << pre[r] - pre[l] << endl;
    }

}