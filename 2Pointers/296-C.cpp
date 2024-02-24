//
// Created by orabi on 2/23/2024.
//
#include <bits/stdc++.h>

using namespace std ;

int main(){
    int n , m , k ;
    cin >> n >> m >> k ;

    vector<long long>input(n+1) ;
    for(int i = 1 ; i <= n ; i++){
        cin >> input[i] ;
    }

    vector<pair<long,long>>lr(m+1) ;
    vector<long long>operation_power(m+1,0);
    for(int i = 1 ; i <= m ; i++){
        cin >> lr[i].first >> lr[i].second ;
        cin >> operation_power[i] ;
    }

    vector<long long>oper_freq(m+1,0);
    for(int i = 1 ; i <= k ; i++){
        int l , r ;
        cin >> l >> r ;
        if(r == m){
            oper_freq[l] = oper_freq[l] + 1 ;
        }else{
            oper_freq[l] = oper_freq[l] + 1 ;
            oper_freq[r+1] -= 1 ;

        }
    }
    //bring suffix array for the number of operations
    for(int i = 1 ; i <= m ; i++){
        oper_freq[i] = oper_freq[i] + oper_freq[i-1] ;
    }
    //for(int x : oper_freq) cout << x << " " ;
    //cout << endl;

    //now go through the operations one by one
    //multiply the value of the operation to be added by the frequency
    //after that place start and finish for the operations
    vector<long long>inp(n+1,0);
    for(int i = 1 ; i <= m ; i++){
       long long sum =  operation_power[i] * oper_freq[i]  ;
       if(lr[i].second == n){
           int index = lr[i].first ;
           inp[index]+=sum ;
       }else{
           int index = lr[i].first ;
           inp[index]+=sum ;
           index = lr[i].second + 1 ;
           inp[index]-=sum ;

       }
    }

    for(int i = 1 ; i <= n ; i++){
        inp[i]+=inp[i-1] ;
        input[i] += inp[i] ;
        cout << input[i] << " " ;
    }





}