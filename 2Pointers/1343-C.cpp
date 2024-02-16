//
// Created by orabi on 2/16/2024.
//
#include <bits/stdc++.h>

using namespace std ;

int main(){



    int t ;
    cin >> t ;
    while(t--) {
        bool first_pos_done = false ;
        bool first_neg_done = false ;

        int pos_index = 0 ;
        int neg_index = 0 ;
        int pos_sz = 0 ;
        int neg_sz = 0 ;
        long long pos_sum = 0 ;
        long long neg_sum = 0 ;

        int n;
        cin >> n;

        vector<int> input(n);
        int holder = 0;
        for (int i = 0; i < n; i++) {
            cin >> holder;
            input[i] = holder;
        }

        for (int i = 0; i < n; i++) {
            if (input[i] > 0) {

                if (first_pos_done) {
                    if (input[i - 1] < 0) {
                        //first positive after negative
                        pos_sum += input[pos_index];
                        pos_sz++ ;
                        pos_index = i;

                        if (i == n - 1) {
                            pos_sum += input[pos_index];
                            pos_sz++ ;
                        }

                    } else {
                        if (input[i] >= input[pos_index]) {
                            pos_index = i;
                        }

                        if (i == n - 1) {
                            pos_sum += input[pos_index];
                            pos_sz++ ;
                        }
                    }
                } else {
                    pos_index = i;
                    first_pos_done = true;
                    if (i == n - 1) {
                        pos_sz++ ;
                        pos_sum += input[pos_index];
                    }
                }
            } else if (input[i] < 0) {
                //we want to start taking negatives after the first pos
                if (first_pos_done) {
                    //this means we came from positvie

                    if (input[i - 1] > 0) {
                        //facing first positive
                        pos_sum += input[pos_index]; //add the greatest
                        pos_sz++ ;

                        pos_index = i;

                        if (i == n - 1) {
                            pos_sum += input[pos_index];
                            pos_sz++ ;

                        }

                    } else {
                        if (input[i] >= input[pos_index]) {
                            pos_index = i;
                        }

                        if (i == n - 1) {
                            pos_sum += input[pos_index];
                            pos_sz++ ;

                        }
                    }
                }
            }
            //------
            if (input[i] < 0) {

                if (first_neg_done) {
                    if (input[i - 1] > 0) {
                        //first positive after negative
                        neg_sum += input[neg_index];
                        neg_sz++ ;
                        neg_index = i;

                        if (i == n - 1) {
                            neg_sum += input[neg_index];
                            neg_sz++ ;
                        }

                    } else {
                        if (input[i] >= input[neg_index]) {
                            neg_index = i;
                        }

                        if (i == n - 1) {
                            neg_sum += input[neg_index];
                            neg_sz++ ;
                        }
                    }
                } else {
                    neg_index = i;
                    first_neg_done = true;
                    if (i == n - 1) {
                        neg_sz++ ;
                        neg_sum += input[neg_index];
                    }
                }
            } else if (input[i] > 0) {
                //we want to start taking negatives after the first pos
                if (first_neg_done) {
                    //this means we came from positvie

                    if (input[i - 1] < 0) {
                        //facing first positive
                        neg_sum += input[neg_index]; //add the greatest
                        neg_sz++ ;

                        neg_index = i;

                        if (i == n - 1) {
                            neg_sz++ ;
                            neg_sum += input[neg_index];
                        }

                    } else {
                        if (input[i] >= input[neg_index]) {
                            neg_index = i;
                        }

                        if (i == n - 1) {
                            neg_sz++ ;
                            neg_sum += input[neg_index];
                        }
                    }
                }
            }

        }

        //hon
        if(neg_sz > pos_sz){
            cout << neg_sum << endl;
        }else if(neg_sz < pos_sz){
            cout << pos_sum << endl;
        }else{
            if(pos_sum > neg_sum)
                cout << pos_sum << endl;
            else
                cout << neg_sum << endl;
        }
    }




}