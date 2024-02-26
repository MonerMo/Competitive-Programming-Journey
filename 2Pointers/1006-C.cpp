//
// Created by orabi on 2/26/2024.
//
#include <bits/stdc++.h>

using namespace std ;

int main(){
    int n ;
    cin >> n ;
    vector<unsigned int>input;
    int holder = 0 ;
    for(int i = 0 ; i < n ; i++){
        cin >> holder ;
        input.emplace_back(holder);
    }

    int low = 0 , high = n-1;
    unsigned long long low_ans = input[low] , high_ans = input[high] ;
    unsigned long long ans = 0 ;
    while(low < high){
        if(low_ans == high_ans){
            //in this case save the ans
            ans = low_ans ;
            low++ , high--;
            low_ans+=input[low] ; high_ans+=input[high] ;
        }else if(low_ans > high_ans){
            high--;
            high_ans+=input[high] ;
        }else if(low_ans < high_ans){
            low++;
            low_ans+=input[low] ;
        }
    }
    cout << ans << endl;

}