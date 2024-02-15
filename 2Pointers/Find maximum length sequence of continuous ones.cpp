//
// Created by orabi on 2/15/2024.
//
#include <bits/stdc++.h>

using namespace std ;

int main(){
    //we want to keep going only if we have one zero if we failed
    //we minimize the range from the left if we keep going
    //increase the range from the right

    //size of the array
    int n ;
    cin >> n ;

    vector<bool> input(n) ;
    bool holder = false ;
    for(int i = 0 ; i < n ; i++){
        cin >> holder ;
        input[i] = holder ;
    }

    int highest = -1 ;
    int zero_index = -1 ;
    int zero_cnt = 0 ;
    int low = 0 , high = 0 ;

    while(high < n){

        if(input[high] == 0){
            zero_cnt++;
            zero_index = high ;
        }


        if(zero_cnt <= 1){
            //we will keep going and take in account the index of
            //the zero we have in our range
            high++ ;
        }else{
            //this means that high reached a the 2nd zero in the range
            //in this case we want to store the highest length and
            //keep taking from the left till we have zero_cnt == 1
            if(highest < (high - low)){
                highest = high - low ;
            }

            //keep taking from the left
            while(zero_cnt > 1){
                if(input[low] == 0){
                    zero_cnt--;
                    zero_index = high ;
                    low++ ;
                }else{
                    low++ ;
                }
            }
            high++ ;
        }
    }
    cout << zero_index << endl;
}