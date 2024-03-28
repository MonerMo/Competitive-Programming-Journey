//
// Created by orabi on 3/28/2024.
//
#include <bits/stdc++.h>

using namespace std ;

bool check(int input){
    bool checker = true ;
    while(input > 0){
        int holder = input % 10 ;
        if(holder != 0 && holder != 1){
            return false ;
        }
        input /= 10 ;
    }
    return checker ;
}

int arr[14] = {10 , 11 , 100 , 101 , 110 , 111 , 1000 , 1001 , 1010 , 1011 , 1100 ,
               1101 , 1110 , 1111};

int main(){
    int t; cin >> t ;
    while(t--){
        int n ; cin >> n ;
        bool not_continue = check(n);
        if(not_continue){
            cout << "YES" << endl;
        }else{

            for(int i = 13 ; i >= 0 ; i--){
                if(n < arr[i]) continue;
                while(n % arr[i] == 0){
                    n /= arr[i] ;
                }
            }
            if(n == 1){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }

    }
}