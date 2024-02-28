//
// Created by orabi on 2/25/2024.
//
#include <bits/stdc++.h>

using namespace std ;

int main(){

    int t ;
    cin >> t ;

    while(t--){
        int n ;
        cin >> n ;

        string holder ;
        cin >> holder ;

        int cnt = 0 ;

        for(int target = 1 ; target <= 9 ; target++){
            int window_sum = 0 ;
            int high = 0 ;
            for(int low = 0 ; low < n ; low++){
                while(window_sum < target && high < n){
                    window_sum+=(holder[high] - '0') ;
                    high++;
                }

                if(window_sum == target && target == (high-low)){
                    cnt++;
                }else{
                    window_sum-=holder[low] - '0' ;
                }
            }
        }
        cout << cnt << endl;
    }

}

