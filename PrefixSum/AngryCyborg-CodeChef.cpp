//
// Created by orabi on 3/9/2024.
//
#include <bits/stdc++.h>

using namespace std ;

int main(){
    int T ;
    cin >> T ;
    while(T--){
        int N ;
        cin >> N ;

        vector<int>output(N+1,0);
        int Q ;
        cin >> Q ;
        while(Q--){
            vector<int>input(N+1,0);

            int l , r ;
            cin >> l >> r ;
            input[l] = 1 ;
            //if(r+1<=N) input[r+1] = -1 ;
            for(int i = l+1 ; i <= r ; i++){
                input[i] += input[i-1] ;
            }


            for(int i = l+1 ; i <= r ; i++){
                input[i] += input[i-1] ;
            }


            for(int i = l ; i <= r ; i++){
                output[i] += input[i] ;
            }
        }

        for(int i = 1 ; i <= N ; i++)
            cout << output[i] << " " ;
        cout << endl;

    }
}