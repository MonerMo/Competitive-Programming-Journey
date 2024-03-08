//
// Created by orabi on 3/3/2024.
//
#include <bits/stdc++.h>

using namespace std ;

const int MAX_SIDE = 1000;
int input[MAX_SIDE+1][MAX_SIDE+1] ;

int main(){
    int n , q ;
    cin >> n >> q ;


    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            char holder ;
            cin >> holder ;
            if(holder == '.'){
                input[i][j] = 0 ;
            }else if(holder == '*'){
                input[i][j] = 1 ;
            }
            input[i][j] += (input[i-1][j] + input[i][j-1] - input[i-1][j-1]);
        }
    }



    while(q--){
        int y1 , x1 , y2 , x2 ;
        cin >> x1 >> y1 >> x2 >> y2 ;
        int ans = input[x2][y2] - input[x1-1][y2] - input[x2][y1-1] + input[x1-1][y1-1] ;
        cout << ans << endl;
    }

}