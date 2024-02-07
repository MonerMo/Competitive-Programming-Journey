//
// Created by orabi on 2/1/2024.
//
#include <bits/stdc++.h>
using namespace std ;

int main(){
    int n , t ;
    cin >> n >> t ;
    vector<int>time ;
    for(int i = 0 ; i < n ; i++){
        int holder = 0 ;
        cin >> holder ;
        time.emplace_back(holder);
    }

    int low = 0 , high = 0 ;
    int ans_low = 0 , ans_high = 0 ;
    int sum = 0 ;
    int max = 0 ;
    while(high <= n-1){
        sum += time[high] ;
        while(sum > t){
            sum -= time[low] ;
            low++;
        }

        if(sum <= t){
            int test = high - low + 1 ;
            if(max < test){
                ans_low = low ;
                ans_high = high ;
                max = test ;
            }
        }
        high++;
    }
    cout << max << endl;
}