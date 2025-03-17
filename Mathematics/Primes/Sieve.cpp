//
// Created by orabi on 12/9/2024.
//
#include <bits/stdc++.h>
using namespace std ;

//we want to calculate the prime numbers from 1 to n inclusive ;
int n = 27720 ;
vector<int>prime(n+1,1);

int main() {
     for(int i = 2 ; i <= n ; i++) {
          //check for the current holding number if it's prime or not
          if(prime[i] == 1) {
               //this means it is prime //store the same value of the number in it
               prime[i] = i ;
               for(int j = i ; i*j <= n ; j++) {
                    //check if prime of j*i have value other than 1 so no need to store in it
                    if(prime[j*i] == 1)
                         prime[j*i] = i ;
                    else
                         continue ;
               }
          }else {
               continue;
          }
     }

     //now after calculating sieve we can print any prime factors for such a number
     int num = 27720 ; //let us try 27720 for example
     while(num != 1) {
          cout << prime[num] << " " ;
          num /= prime[num] ;
     }

}