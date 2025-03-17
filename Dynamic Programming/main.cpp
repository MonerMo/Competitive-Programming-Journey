#include <bits/stdc++.h>
using namespace std ;

int main() {

        //we can do it by two pointers and set
        string s = "anviaj" ;

        set<char> freq ;
        int st = 0 ; int e = 0 ;
        int ans = -1 ;
        for( ; e < s.size() ;){

            if(freq.find(s[e]) == freq.end()){
                //this means the element is not yet exist
                freq.insert(s[e]);
                e++ ;
                int holder = freq.size();
                if(holder > ans) ans = holder ;
            }else{
                //this means we hit a character that breaks the current substring

                //if the current end are similar to the past char so we should start from the distinct
                if(s[e] == s[e-1]) {
                    freq.clear() ;
                    st = e ;
                }else {
                    freq.erase(s[st]);
                    st++ ;
                }
            }
        }
        if(ans == -1)
            cout << 0 ;
        else
            cout <<  ans ;
}
