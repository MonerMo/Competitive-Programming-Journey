//
// Created on 12/15/2024.
//
//created by MoniirMo
#include <bits/stdc++.h>
using namespace std ;



int main() {
    int t;
    cin >> t ;
    while(t--) {
        int n ;
        cin >> n ;
        vector<bool>freq(n+1,false);
        vector<int>ans;
        int holder ;
        int start = 1 ;
        for(int i = 0 ; i < n ; i++) {
            cin >> holder ;
            if(!freq[holder]) {
                ans.push_back(holder) ;
                freq[holder]=true;
            }else {
                while(freq[start]) {
                    start++ ;
                }
                ans.push_back(start);
                freq[start]=true ;
            }
        }
        for(int output : ans) cout << output << " " ;
        cout << endl;
    }
}
