//
// Created by orabi on 3/11/2024.
//
#include <bits/stdc++.h>

using namespace std ;

const int N = 1001 ;
const int M = 1001 ;
int arr[N][M] = {0};


int main(){

    int n , m ;
    cin >> n >> m ;


    for(int i = 1 ; i <= n ; i++){
        string holder ;
        cin >> holder ;
        for(int j = 1 ; j <= m ; j++){
            arr[i][j] = (holder[j-1] - '0');
        }
    }

    int q ;
    cin >> q ;

    while(q--){
        int x1 , y1 , x2 , y2 ;
        cin >> x1 >> y1 >> x2 >> y2 ;
        
    }


}