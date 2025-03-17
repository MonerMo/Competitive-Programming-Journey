//
// Created on 12/15/2024.
//
//created by MoniirMo
#include <bits/stdc++.h>
using namespace std ;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s ;
        string ans ;
        cin >> s ;
        for(int i = s.size() ; i >= 0; i--) {
            if(s[i] == 'q') {
                ans.push_back('p') ;
            }else if(s[i] == 'p') {
                ans.push_back('q') ;
            }else if(s[i] == 'w') {
                ans.push_back('w') ;
            }
        }
        cout << ans << endl;
        ans = "" ;
    }

}
