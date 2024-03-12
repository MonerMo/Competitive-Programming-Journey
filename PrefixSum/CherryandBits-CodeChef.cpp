//
// Created by orabi on 3/11/2024.
//
#include <bits/stdc++.h>

using namespace std ;

const int N = 1002 ;
const int M = 1002 ;
int arr[N][M] = {0};
long long oper[N][M] = {0};


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
        //we will apply the queries on oper 2d array
        oper[x1][y1] += 1 ;
        oper[x2+1][y2+1] += 1 ;
        oper[x1][y2+1] -= 1 ;
        oper[x2+1][y1] -= 1 ;
        
    }


    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++) {
            //now we want to calculate the prefix sum
            oper[i][j] = oper[i][j] + oper[i][j-1] + oper[i-1][j] - oper[i-1][j-1] ;
            int flip = oper[i][j] % 2 ;
            if(flip == true){
                if(arr[i][j] == 1)
                    arr[i][j] = 0 ;
                else
                    arr[i][j] = 1 ;
            }else{

            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++) {
            //now we want to calculate the prefix sum
            cout << arr[i][j];
        }
        cout << endl;
    }




}