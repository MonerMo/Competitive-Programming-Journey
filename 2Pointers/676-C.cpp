//
// Created by orabi on 2/7/2024.
//
#include <bits/stdc++.h>

using namespace std ;

int main(){
    int sz , k  ;
    cin >> sz >> k ;

    string input ;
    cin >> input ;

    int a_low = 0 , a_high = 0 ;
    int b_low = 0 , b_high = 0 ;
    int ans_low = 0 , ans_high = 0 ;
    int ans1_low = 0 , ans1_high = 0 ;

    int bs_freq = 0 ;
    int as_freq = 0 ;

    while(a_high < sz && b_high < sz){
        //first we want to go for the longest a's with k b's inside it
        //if b's is less than or equal to k then keep going
        //if b's is more than k then remove from the beginning till b's is equal to k
        if(input[a_high] == 'b'){
            bs_freq++ ;
        }
        //now we want to check for the input if correct or not
        if(bs_freq <= k){
            //keep going
            if(ans_high - ans_low < a_high - a_low){
                ans_high = a_high ;
                ans_low = a_low ;
            }
            a_high++ ;
        }else{
            //the insert is wrong means that we need to remove from the beginning
            while(bs_freq > k){
                if(input[a_low] == 'b'){
                    bs_freq-- ;
                    a_low++;
                }else{
                    a_low++;
                }
            }
            a_high++;
        }


        if(input[b_high] == 'a'){
            as_freq++ ;
        }
        //now we want to check for the input if correct or not
        if(as_freq <= k){
            //keep going
            if(ans1_high - ans1_low < b_high - b_low){
                ans1_high = b_high ;
                ans1_low = b_low ;
            }
            b_high++ ;
        }else{
            //the insert is wrong means that we need to remove from the beginning
            while(as_freq > k){
                if(input[b_low] == 'a'){
                    as_freq-- ;
                    b_low++;
                }else{
                    b_low++;
                }
            }
            b_high++;
        }
    }
    int ans1 =  ans1_high - ans1_low + 1 ;
    int ans2 = ans_high - ans_low + 1 ;
    if(ans1 >= ans2){
        cout << ans1 << endl ;
    }else{
        cout << ans2 << endl;
    }

}