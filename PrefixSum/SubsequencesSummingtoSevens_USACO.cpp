//
// Created by orabi on 2/20/2024.
//

#include <bits/stdc++.h>

using namespace std ;

int main(){

    ifstream cin ("div7.in");
    ofstream cout ("div7.out");

    int n ;
    cin >> n ;

    vector<long long>input(n+1,0);
    for(int i = 1 ; i <= n ; i++){
        cin >> input[i] ;
        input[i] = ((input[i] + input[i-1]) % 7) ;
    }

    //now we want to save the first occurrence for each number
    vector<int>first(7,-1);
    int maximum = 0 ;
    for(int i = 1 ; i <= n ; i++){
        if(first[input[i]] == -1){
            first[input[i]] = i ;
        }else{
            //in this case we want to calculate the largest index
            if(i - first[input[i]] > maximum){
                maximum = i - first[input[i]] ;
            }
        }
    }
    cout << maximum << endl;
}