//
// Created by orabi on 2/8/2024.
//
#include <bits/stdc++.h>

using namespace std ;

int main(){
    int n ;
    cin >> n ;

    while(n--){
        string input ;
        cin >> input ;

        set<int>sizes ;

        int a = 0 , b = 0 , c = 0 ;
        int low = 0 , high = 0 ;
        int ans_low = 0 , ans_high = 0 ;
        int sz = input.size();

        while(high < sz){
            if(input[high] == '1')
                a++;
            else if(input[high] == '2')
                b++;
            else
                c++;

            //if any letter of the three letters is still not equal one
            //then keep going adding to the string
            if(a < 1 || b < 1 || c < 1){
                //the last time we will enter this condition means that
                //the last insert was the first appearance of the letter
                high++ ;
            }else{
                //in this case we want to remove from the beginning till
                //the frequency of a , b or c is less than or equal to 1

                while(a >= 1 && b >= 1 && c >= 1){

                    int holder = high - low + 1;
                    sizes.emplace(holder);


                    if(input[low] == '1')
                        a--;
                    else if(input[low] == '2')
                        b--;
                    else
                        c--;

                    low++;
                }
                high++;
            }
        }
        cout << *(sizes.begin()) << endl;
    }
}