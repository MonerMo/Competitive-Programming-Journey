//
// Created by orabi on 11/24/2024.
//
#include <bits/stdc++.h>

using namespace std ;
int n ;
vector<int>first(100005,0) ;
vector<int>second(100005,0) ;
vector<int>third(100005,0);
int const small = -1e9+5 ;

//we want to memoize at each day and at each event
int mem[100005][3] ;
int solve(int choice, int day_num) {
    //this means we reached the end of the days
    if(day_num == n)
        return 0 ;

    if(mem[day_num][choice] != -1)
        return mem[day_num][choice] ;

    int ans = small ;
    if(choice != 0) {
        //this means we will choose swimming
         ans = max(ans, first[day_num] + solve(0,day_num+1));
    }

    if(choice != 1) {
        //this means we will choose catching bugs
        ans = max(ans, second[day_num] + solve(1,day_num+1));
    }

    if(choice != 2) {
        //this means we will choose swimming
         ans = max(ans, third[day_num] + solve(2,day_num+1));
    }

    return mem[day_num][choice] = ans ;
}


int main() {
    //we will have an entry for each day
    n ;
    cin >> n ; //taking the number of days

    for(int i = 0 ; i < 100005 ; i++) {
        for(int j = 0 ; j < 3 ; j++) {
            mem[i][j] = -1 ;
        }
    }

    for(int i = 0 ; i < n ; i++) {
        cin >> first[i] >> second[i] >> third[i] ;
    }

    //we should be aware of the prev choice and the day we are in
   cout << solve(3,0);
}