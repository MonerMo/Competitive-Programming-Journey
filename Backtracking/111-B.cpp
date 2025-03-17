//
// Created by orabi on 11/20/2024.
//
#include <bits/stdc++.h>

using namespace std ;

bool solve(string input_s, int half_size, int cur_i,int cur_si, short comp) {
    //base case
    if(cur_si == half_size*2) {
        return false ;
    }

    if(cur_i == half_size) return true ;

    //transition
    if(comp == 0) {
        //to check the luck of being greater
        if(((input_s[cur_i] - '0') > (input_s[cur_si] - '0')) && (input_s[cur_si] != 'X')) {
            //in this case you mark the current_si number
            input_s[cur_si] = 'X' ;
            return true && solve(input_s, half_size, cur_i+1, half_size, comp);
        }else {
            return solve(input_s, half_size, cur_i, cur_si+1, comp);
        }
    }else if(comp == 1) {
        //to check the luck of being smaller
        if(((input_s[cur_i] - '0') < (input_s[cur_si] - '0')) && (input_s[cur_si] != 'X')) {
            //in this case you mark the current_si number
            input_s[cur_si] = 'X' ;
            return true && solve(input_s, half_size, cur_i+1, half_size, comp);
        }else {
            return solve(input_s, half_size, cur_i, cur_si+1, comp);
        }
    }
}


int main() {
    int n ;
    cin >> n ;

    string input_s ;
    cin >> input_s ;
    vector<int>sorted_string(2*n , 0);
    for(int i = 0 ; i < 2*n ; i++) {
        sorted_string[i] = input_s[i] - '0' ;
    }
    sort(sorted_string.begin() , sorted_string.begin()+n) ;
    sort(sorted_string.begin()+n , sorted_string.begin()+(2*n));
    for(int i = 0 ; i < 2*n ; i++) {
        input_s[i] = '0' + sorted_string[i] ;
    }


    //for the compare parameter
    //0 means do it for bigger
    //1 means do it for smaller
    bool bigger_status = solve(input_s, n, 0,n, 0);
    bool smaller_status = solve(input_s, n , 0, n, 1);

    if((bigger_status == true) && (smaller_status == false)) {
        cout << "YES" ;
    }else if((smaller_status == true) && (bigger_status == false)){
        cout << "YES" ;
    }else {
        cout << "NO" ;
    }
}