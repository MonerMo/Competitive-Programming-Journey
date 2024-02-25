//
// Created by orabi on 2/21/2024.
//
#include <bits/stdc++.h>

using namespace std ;

int main(){

    ifstream cin ("hps.in");
    ofstream cout ("hps.out");


    int n ;
    cin >> n ;
    vector<char>input(n);
    vector<int>h0(n+1,0);
    vector<int>p0(n+1,0);
    vector<int>s0(n+1,0);
    int h = 0 , p = 0 , s = 0 ;
    for(int i = 0 ; i < n ; i++){
        cin >> input[i] ;
        if(input[i] == 'H') {
            h++;
            h0[i+1]++; h0[i+1] += h0[i] ;
            p0[i+1] += p0[i] ;
            s0[i+1] += s0[i] ;
        }else if(input[i] == 'P') {
            p++;
            p0[i+1]++; p0[i+1] += p0[i] ;
            h0[i+1] += h0[i] ;
            s0[i+1] += s0[i] ;
        }else {
            s++;
            s0[i+1]++; s0[i+1] += s0[i] ;
            p0[i+1] += p0[i] ;
            h0[i+1] += h0[i] ;
        }
    }
    //for(int x : h0) cout << x << " " ; cout << endl;
    //for(int x : p0) cout << x << " " ; cout << endl;
    //for(int x : s0) cout << x << " " ; cout << endl;

    int sum = 0 ;
    for(int i = 1 ; i <= n ; i++ ){
        int before = max(h0[i],max(p0[i],s0[i]));
        int after = max((h0[n]-h0[i]),max((p0[n]-p0[i]),(s0[n]-s0[i]))) ;
        int holder = after + before ;
        sum = max(sum , holder);
    }
    cout << sum << endl;





}