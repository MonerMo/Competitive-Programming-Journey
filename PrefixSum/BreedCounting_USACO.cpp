//
// Created by orabi on 2/20/2024.
//
#include <bits/stdc++.h>

using namespace std ;

int main(){

    ifstream cin ("bcount.in");
    ofstream cout ("bcount.out");

    int n , q ;
    cin >> n >> q ;

    vector<unsigned int>f(n+1,0) ;
    vector<unsigned int>s(n+1,0);
    vector<unsigned int>t(n+1,0);

    short holder = 0 ;
    for(int i = 1 ; i <= n ; i++){
        cin >> holder ;
        if(holder == 1){
            f[i] = 1 ;
            f[i] = f[i] + f[i-1] ;
            s[i] = s[i-1] ;
            t[i] = t[i-1] ;
        }else if(holder == 2){
            s[i] = 1 ;
            s[i] = s[i] + s[i-1] ;
            f[i] = f[i-1] ;
            t[i] = t[i-1] ;
        }else if(holder == 3){
            t[i] = 1 ;
            t[i] = t[i] + t[i-1] ;
            s[i] = s[i-1] ;
            f[i] = f[i-1] ;
        }
    }

    //for(int x : f) cout << x << " " ; cout << endl;
    //for(int y : s) cout << y << " " ; cout << endl;
    //for(int z : t) cout << z << " " ; cout << endl;

    while(q--){
        int x , y ;
        cin >> x >> y ;
        cout << f[y] - f[x-1] << " " << s[y] - s[x-1] << " " << t[y] - t[x-1] << "\n" ;
    }
}