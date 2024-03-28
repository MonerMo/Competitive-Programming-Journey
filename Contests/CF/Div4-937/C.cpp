//
// Created by orabi on 3/28/2024.
//
#include <bits/stdc++.h>

using namespace std ;

void time_print(int h , int min){
    if(h < 10){
        cout << '0' << h ;
    }else{
        cout << h ;
    }

    cout << ':' ;
    if(min < 10){
        cout << '0' << min ;
    }else{
        cout << min ;
    }
}


int main(){
    int t;
    cin >> t ;
    while(t--){
        string input ;
        cin >> input ;

        int hour = ( (input[0] - '0') * 10 ) + ( input[1] - '0' ) ;
        int minutes = ( (input[3] - '0') * 10 ) + ( input[4] - '0' ) ;

        if(hour <= 11){
            if(hour == 0) {
                time_print(12, minutes);
            }else{
                time_print(hour , minutes);
            }
            //am hour
            cout << " AM" << endl;
        }else{
            if(hour == 12){
                time_print(12, minutes);
                cout << " PM" << endl;
            }else{
                time_print(hour%12 , minutes);
                cout << " PM" << endl;
            }
        }
    }
}