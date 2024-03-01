//
// Created by orabi on 3/1/2024.
//
#include <bits/stdc++.h>

using namespace std ;

int main(){
    int n ;
    cin >> n ;

    vector<long long>input(n+1,0);
    for(int i = 1 ; i <= n ; i++) {
        cin >> input[i];
        input[i] += input[i-1] ;

    }
    //for(int x : input) cout << x << " " ; cout << endl;
    long long small = 0 ;
    long long large = INT64_MIN ;
    int small_ind = 0 ;

    for(int i = 1 ; i<= n ; i++){
        long long holder = input[i] - input[small_ind] ;
        if(holder > large){
            large = holder ;
        }
        if(input[i] < small){
            small = input[i] ;
            small_ind = i ;
        }
    }

    cout << large << endl;




}