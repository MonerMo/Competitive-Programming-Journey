//
// Created by orabi on 12/5/2024.
//
#include <bits/stdc++.h>

using namespace std ;

int dp[3002][3002] ;

int main() {
    string input1 , input2 ;
    cin >> input1 >> input2 ;

    int sz_1 , sz_2 ;
    sz_1 = input1.size() ;
    sz_2 = input2.size() ;

    for(int i = 0 ; i <= sz_1 ; i++) {
        for(int j = 0 ; j <= sz_2 ; j++) {
            //now we want to loop
            if(i == 0 || j == 0) {
                dp[i][j] = 0 ;
            }else if(input1[i-1] == input2[j-1]) {
                //this means that we found equal letter
                dp[i][j] = dp[i-1][j-1] + 1 ; //add one to the diagonal
            }else {
                //in this case means that they are not equal
                //take the maximum between the row and col
                dp[i][j] = max(dp[i][j-1] , dp[i-1][j]) ;
            }
        }
    }

    //now we want to traverse the dp
    vector<char>output ;
    int i = sz_1 , j = sz_2 ;
    while(i > 0 && j > 0) {
        //if the current pos equal then go to diagonals , if not go to max between row and col
        if(input1[i-1] == input2[j-1]) {
            //this means they are equal
            output.push_back(input1[i-1]) ;
            i-- , j-- ;
        }else if(dp[i][j-1] > dp[i-1][j]) {
            //this means that we go to the prev col
            j-- ;
        }else {
            //this means that either prev row bigger than or equal to the prev col
            i-- ;
        }
    }

    int sz = output.size();
    for(int idx = sz-1 ; idx >= 0 ; idx--)
        cout << output[idx] ;



}