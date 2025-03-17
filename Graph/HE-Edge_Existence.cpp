//
// Created by orabi on 12/14/2024.
//
#include <bits/stdc++.h>
using namespace std ;
int main() {
    int n , m ;
    cin >> n >> m ;
    bool graph[1003][1003] ;
    int a , b ;
    for(int i = 0 ; i < m ; i++) {
        cin >> a >> b ;
        graph[a][b] = true ;
    }
    cin >> n ;
    for(int i = 0 ; i < n ; i++) {
        cin >> a >> b ;
        if(graph[a][b])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}