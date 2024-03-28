//
// Created by orabi on 3/28/2024.
//
#include <bits/stdc++.h>

using namespace std ;

void hash_block(){
    cout << "##" ;
}
void dot_block(){
    cout << ".." ;
}


int main(){
    int t ;
    cin >> t ;
    while(t--){
        string arr[3] ;
        arr[1] = "##" ;
        arr[2] = ".." ;
        int n ;
        cin >> n ;
        int row_flag = 1 ;
        int block_flag = 1 ;

        if(n == 1){
            cout << "##" << endl;
            cout << "##" << endl;
            continue;
        }
        for(int row = 1 ; row <= 2*n ; row++){
            for(int col = 1 ; col <= n ; col++){
                if(row_flag == 1 && block_flag == 1){
                    cout << "##" ;
                }else if(row_flag == 1 && block_flag == -1){
                    cout << ".." ;
                }else if(row_flag == -1 && block_flag == 1){
                    cout << ".." ;
                }else if(row_flag == -1 && block_flag == -1){
                    cout << "##" ;
                }
                block_flag *= -1 ;
            }
            cout << endl;
            if(n&1) block_flag *= -1 ;
            if(row % 2 == 0) row_flag *= -1 ;
        }

    }
}