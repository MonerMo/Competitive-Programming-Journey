//
// Created by m_ora on 06/02/2024.
//

#include <bits/stdc++.h>

using namespace std ;

int main(){
    int t ;
    cin >>t ;
    while(t--){
        int n ;
        cin >> n ;

        vector<int> v ;

        int holder = 0 ;
        for(int i = 0 ; i < n ; i++){
            cin >> holder ;
            v.emplace_back(holder) ;
        }

        int sz = v.size() ;
        int low = 0 , high = sz - 1 ;
        while(low < high){
            cout << v[low] << " " << v[high] << " ";
            low++ ;
            high-- ;
        }

        if(sz % 2 != 0)
            cout << v[sz/2] << endl;
        else
            cout << endl;

    }
}
