//
// Created by orabi on 11/29/2024.
//
#include <bits/stdc++.h>
using namespace std ;

int n ;
int x ;
vector<int>price(n+1,0);
vector<int>pages(n+1,0);
int dp[1001][100005] ;

int main() {


    cin >> n; //number of books
    cin >> x ; //price of the book ;

    for(int i = 1 ; i <= n ; i++) {
        int holder ;
        cin >> holder ;
        price.push_back(holder);
    }
    for(int i = 1 ; i <= n ; i++) {
        int holder ;
        cin >> holder ;
        pages.push_back(holder);
    }

    //looping for each item we have
    for(int book_num = 1 ; book_num <= n ; book_num++) {
        //using each item we check if we can use it in the current book cost
        for(int book_cost = 1 ; book_cost <= x ; book_cost++) {
            //now we want to take the maximum between the value of the past element for the same book cost
            //or the value of the current element taken
            if( book_cost - price[book_num]  >=0 ) {
                dp[book_num][book_cost] = max(dp[book_num-1][book_cost] , pages[book_num] + dp[book_num-1][book_cost - price[book_num]]) ;
            }else {
                dp[book_num][book_cost] = dp[book_num-1][book_cost] ;
            }
        }
    }
    cout << dp[n][x] << endl;

}