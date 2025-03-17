//
// Created by orabi on 11/23/2024.
//
#include <bits/stdc++.h>
#include <sstream>
using namespace std ;


int r[21] = {0};
int g[21] = {0};
int b[21] = {0};
int num_of_houses ;

const int oo = (int)1e6;

int minCost(int status, int i) {
    //first we want to check for the i
    if(i == num_of_houses)
        return 0;

    int ret = oo ;

    //now we want to start with any value randomly
    if(status != 0) {
        //now we choose the red color.
        ret = min(ret, r[i]+ minCost(0,i+1));
    }

    if(status != 1) {
        //now we choose the red color.
         ret = min(ret, g[i]+ minCost(1,i+1));
    }

    if(status != 2) {
        //now we choose the red color.
         ret = min(ret, b[i]+ minCost(2,i+1));
    }

    return ret ;
}

class RGBStreet {
public:
    int estimateCost(vector<string> houses) {
        for(int i = 0 ; i < houses.size() ; i++) {
            istringstream iss(houses[i]) ;
            iss >> r[i] >> g[i] >> b[i] ;
        }
        num_of_houses = houses.size() ;

        //now we want to calculate the minimum cost after taking the input .
        int holder = minCost(3,0);
        return holder ;
    }


};



int main() {

    vector<string> input = {"26 40 83", "49 60 57", "13 89 99"} ;
    RGBStreet test;
    cout << test.estimateCost(input);

}