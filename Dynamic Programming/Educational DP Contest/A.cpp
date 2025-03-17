//
// Created by orabi on 9/6/2024.
//
#include "bits/stdc++.h"

using namespace std ;

int n ;
vector<int>input(10005);
vector<int>dp(10005, -1);
int frog(int index, int val){
    //base case where the index of the array is less than n
    if(index > n)
        return 0 ;

    //now we should to 2^n complexity recurrences
    //we should go in the i+1 path and in the i+2 path and keep adding the differences
    int one = val + abs(input[index] - input[index+1]) + frog(index+1 , val) ;
    int two = val + abs(input[index] - input[index+2]) + frog(index+2 , val);

    return min(one,two);

}


int main(){
    cin >> n ;
    //we are initially on stone 1

    for(int i = 0 ; i < n ; i++){
        cin >> input[i] ;
    }

    cout << frog(0,0);



}