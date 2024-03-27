//
// Created by orabi on 3/27/2024.
//
#include <iostream>
#include <bits/stdc++.h>


using namespace std;

#define MAX 10e5+1

vector<long long>memory(MAX,-1);



long long fact(long long holder){

    memory[0] = memory[1] = 1 ;

    //first check for the existance
    if(memory[holder] != -1)
        return memory[holder] ;

    //either than this calculate it normally as recursion
    return memory[holder] = ( ( ( holder % 1000000007 ) * ( fact(holder-1) % 1000000007) ) % 1000000007 ) ;
}


int main() {
    int T ;
    cin >> T ;

    while(T--){
        long long input ;
        cin >> input ;
        cout << fact(input) << endl;
    }
}