//
// Created by orabi on 12/7/2024.
//
#include <bits/stdc++.h>
using namespace std ;

int input[100] ;
vector<int>d(100,1);
vector<int>idx(100,0);
int main() {

    int sz ;
    cin >> sz ;

    for(int i = 1 ; i <= sz ; i++) {
        cin >> input[i] ;
    }

    //we will loop for each i and for each i we will loop for each j to find the greatest LIS where a[j] < a[i]
    //if we want to retrieve the LIS we want to use idx array to put in each index the greatest ancestor
    for(int i = 1 ; i <= sz ; ++i) {
        for(int j = 1 ; j < i ; ++j) {
            if(input[j] < input[i]) {
                if(d[i] < max(d[i],d[j]+1)) {
                    d[i] = max(d[i] , d[j]+1) ;
                    idx[i] = j ;
                }
            }
        }
    }
    int ans = 0 ;
    int great_idx = 0 ;
    for(int i = 1 ; i <= sz ; i++) {
        if(ans < max(ans,d[i])) {
            ans = max(ans , d[i]);
            great_idx = i ;
        }
    }

    int i = great_idx ;
    while(d[i] != 1) {
        cout << input[i] << " " ;
        i = idx[i] ;
    }
    cout << input[i] ;


}