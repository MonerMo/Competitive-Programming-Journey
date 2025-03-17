//
// Created by orabi on 12/15/2024.
//
#include <bits/stdc++.h>
using namespace std ;

vector<int> lang[102] ;
vector<int> edges[102] ;
vector<bool>visited(102,false);

void dfs(int u) {
    if(visited[u]) return ;
    visited[u] = true ;
    for(int i = 0 ; i < edges[u].size() ; i++) {
        dfs(edges[u][i]) ;
    }
}



int main() {


    int n , m ;
    cin >> n >> m ;
    //for each language put the employees that talk that language
    //after that loop on each language and connect
    bool all_zeros = true ;
    int num_of_lang ;
    for(int i = 1 ; i <= n ; i++) {
        cin >> num_of_lang ;
        if(num_of_lang != 0) all_zeros = false ;
        int holder ;
        for(int j = 0 ; j < num_of_lang ; j++) {
            cin >> holder ;
            lang[holder].push_back(i);
        }
    }

    //now we need to loop for each language and connect the employees
    for(int i = 1 ; i <= m ; i++) {
        int index = 0 ;
        while(index+1 < lang[i].size()) {
            //then we need to make lang[i][index] is adjacent to lang[i][index+1] ;
            edges[lang[i][index]].push_back(lang[i][index+1]);
            edges[lang[i][index+1]].push_back(lang[i][index]);
            index++ ;
        }
    }

    //now we need to loop for each employee and check the number of connected components
    int connected = 0 ;
    for(int i = 1 ; i <= n ; i++) {
        if(!visited[i]) {
            dfs(i);
            connected++;
        }
    }
    if(connected == n && all_zeros == true)
        cout << connected << endl;
    else
        cout << connected - 1 << endl;
}
