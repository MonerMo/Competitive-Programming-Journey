//
// Created by orabi on 3/14/2024.
//
#include <bits/stdc++.h>

using namespace std ;

int main(){
    int n ;
    cin >> n ;
    vector<int>input ;
    for(int i = 0 ; i < n ; i++){
        int holder ;
        cin >> holder ;
        input.emplace_back(holder);
    }

    sort(input.begin(), input.end());


    int q ;
    cin >> q ;
    while(q--){
        int coins ;
        cin >> coins ;
        int ans = 0 ;
        int l = 0 , r = n-1 ;
        while(l <= r){
            int m = l + ( (r-l) / 2 ) ;
            if(coins >= input[m]){
                ans = m + 1 ;
                l = m + 1 ;
            }else{
                r = m - 1 ;
            }
        }
        cout << ans << endl;
    }
}