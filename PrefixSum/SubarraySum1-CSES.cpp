//
// Created by orabi on 2/28/2024.
//
#include <bits/stdc++.h>

using namespace std ;

int main(){
    int n , target ;
    cin >> n >> target ;

    vector<long long>input(n+1,0);
    for(int i = 1 ; i <= n ;i++){
        cin >> input[i] ;
        input[i] += input[i-1] ;
    }

    map<long long , int>already_seen ;
    int cnt = 0 ;
    for(int i = 0 ; i <= n ; i++){
        long long diff = input[i] - target ;

        if(already_seen.find(diff) == already_seen.end()){
            //this means that the diff we wanted is not found
            //so we will check if the current number of prefix is added or not
            if(already_seen.find(input[i]) == already_seen.end()){
                //this means that this is the first time we encounter
                //then we will add it
                already_seen.emplace(make_pair(input[i],1));
            }else{
                //already exist then add 1 to it
                already_seen[input[i]]++ ;
            }
        }else{
            //we found the diff
            cnt += already_seen[diff] ;
            //so we will check if the current number of prefix is added or not
            if(already_seen.find(input[i]) == already_seen.end()){
                //this means that this is the first time we encounter
                //then we will add it
                already_seen.emplace(make_pair(input[i],1));
            }else{
                //already exist then add 1 to it
                already_seen[input[i]]++ ;
            }
        }
    }
    cout << cnt << endl;



}