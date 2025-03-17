//
// Created by orabi on 12/5/2024.
//
#include <bits/stdc++.h>
using namespace std ;

int dp[5002][5002] ;

int main() {
 string input1, input2 ;
 cin >> input1 >> input2 ;
 int sz_1 = input1.size() ;
 int sz_2 = input2.size();

//now we want to hold the case when any one of them is empty
 for(int i = 0 ; i <= sz_1 ; i++)
  dp[i][0] = i ;
 for(int j = 0 ; j <= sz_2 ; j++)
  dp[0][j] = j ;

 //now we want to loop over each substring of X with each one of Y .
 for(int i = 1 ; i <= sz_1 ; i++) {
  for(int j = 1 ; j <= sz_2 ; j++) {
    //check first in the case if equality or not
   int step_size = 0 ;
   if(input1[i-1] == input2[j-1]) {
    step_size = 0 ;
   }else if(input1[i-1] != input2[j-1]) {
    step_size = 1 ;
   }

  //now the answer of the dp
   dp[i][j] = min( min( dp[i][j-1] + 1, dp[i-1][j] + 1) , dp[i-1][j-1] + step_size ) ;

  }
 }
 cout << dp[sz_1][sz_2] ;
}