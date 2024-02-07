//
// Created by orabi on 2/1/2024.
//
#include <bits/stdc++.h>
using namespace std ;

int main(){
    string input = "abcbdbdbbdcdabd" ;

    //we want to have window pointers and answer pointers
    //we will loop with the size of the string
    //also we want to have the highest size of the substring
    //we want to have a (k) variable for the number of distinct elements
    int k = 5 ;
    int low = 0 , high = 0 ;
    int ans_l = 0 , ans_h = 0 ;
    int maximum_size = 0 ;
    int maximum_distinct = 0 ;

    int freq[26] = {0};
    int distinct = 0 ;

    int sz = input.size() ;
    for(; high < sz ; ){
        int asci = input[high] - 'a' ;
        //if the new added character first time to get added
        if(freq[asci] == 0){
            freq[asci]++;
            distinct++;
        }else{
            //update it's frequency
            freq[asci]++;
        }

        //now we want to check after adding the new element if the window is stable
        if(distinct > k){
            //if number of distinct characters > k
            //now we need to remove from the beginning of the string
            while(distinct > k) {
                int ascii = input[low] - 'a';
                freq[ascii]--;
                if (freq[ascii] == 0) {
                    distinct--;
                }
                low++;
            }
            //cout << "-low = " << low << " -high = " << high << endl;
        }else if(distinct <= k){
            //substring is stable
            if(distinct == k) {
                int test = high - low + 1;
                if (test > maximum_size) {
                    maximum_size = test;
                    ans_h = high;
                    ans_l = low;
                    maximum_distinct = distinct ;
                }
            }
        }
        high++ ;
        //cout << "low = " << low << " high = " << high << " distinct=" << distinct << endl;

    }


    for(int i = ans_l ; i <= ans_h ; i++){
        cout << input[i] ;
    }




}