//
// Created by orabi on 3/8/2024.
//
#include <bits/stdc++.h>

using namespace std ;

int main(){

    int n ;
    cin >> n ;
    vector<long long>input(n+1,0);
    vector<long long>sorted(n+1,0);
    for(int i = 1 ; i <= n ; i++){
        cin >> input[i] ;
        sorted[i] = input[i] ;
        input[i] += input[i-1] ;
    }

    sort(sorted.begin(),sorted.end());
    for(int i = 1 ; i <= n ;i++){
        sorted[i] += sorted[i-1] ;
    }

    int q ;
    cin >> q ;

    while(q--){
        int type ;
        cin >> type ;
        int first , last ;
        cin >> first >> last ;
        if(type == 2){
            cout << sorted[last] - sorted[first-1] << endl;
        }else if(type == 1){
            cout << input[last] - input[first-1] << endl;
        }
    }
}