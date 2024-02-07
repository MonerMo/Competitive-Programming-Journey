//
// Created by orabi on 2/7/2024.
//
#include <bits/stdc++.h>

using namespace std ;

int main(){
    string input ;
    cin >> input ;

    int freq[26] = {0};
    int ans_low = 0 , ans_high = 0 ;
    int low = 0 , high = 0 ;

    int sz = input.size() ;
    while(high < sz){
        //first insert the letter
        int index = input[high] - 'a' ;
        freq[index]++ ;

        //now we want to check if the insert of the letter is correctly
        //1.insert is correctly if the frequency of the letter is <= 1
        //2.insert is incorrectly if the frequency of the letter = 2

        if(freq[index] <= 1){
            //insert is correctly now we increase the high
            if(ans_high - ans_low  < high - low ){
                ans_low = low ;
                ans_high = high ;
            }
            high++ ;

        }else{
            //this means that the insert is incorrectly
            //we need to delete from the low index till we find the letter duplicate at
            //the beginning and remove it after that increase the low
            while((freq[index]) > 1){
                int i = input[low] - 'a' ;
                freq[i]-- ;
                low++ ;
            }

            high++ ;
        }

    }
    for(int i = ans_low ; i <= ans_high ; i++){
        cout << input[i] ;
    }

}