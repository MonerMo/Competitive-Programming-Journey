//
// Created by orabi on 3/28/2024.
//
#include <bits/stdc++.h>
using namespace std ;


int main(){

    long long N ;
    int t ;

    cin >> N >> t ;
    while(N != 0 && t != 0){
        long long a , b ;
        char op ;
        while(t--){
            cin >> a >> op >> b ;

            a %= N ;
            b %= N ; //taking mod for both

            //now we want to check for the operation
            if(op == '+'){
                cout << ( ( a + b ) % N) << endl;
            }else if(op == '-'){
                cout << ( ( a - b + N) % N) << endl;
            }else if(op == '*'){
                cout << ( ( a * b ) % N) << endl;
            }else if(op == '/'){
                if(gcd((long long)N,2) != 1){
                    //this means that N is not prime
                    cout << -1 << endl;
                }else{

                }
            }
        }
    }

}