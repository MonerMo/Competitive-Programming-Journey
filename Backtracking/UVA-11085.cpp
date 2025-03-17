//
// Created by orabi on 11/22/2024.
//
#include <bits/stdc++.h>

using namespace std ;
int col_place_in_row[9] = {0};
int col_place_in_row_used[9] = {0} ;

//we want to have an array to keep track of the possible rows & left diagonal and right diagonal
int visited_col[9] = {0} ;
int right_diagonals[20] = {0} ;
int left_diagonals[20] = {0} ;
int sum = 999 ;

void solve(int row) {
    if(row == 9) {
        //here we reached a valid solution
        int sum_local = 0 ;
        for(int i = 1 ; i <= 8 ; i++) {
            //col_place_in_row[i] = 9-col_place_in_row[i] ; //to rotate it
            //and now for each index calculate the sum
            if(col_place_in_row[i] != col_place_in_row_used[i])
                sum_local++;

        }
        if(sum_local < sum) sum = sum_local ;
        return ;
    }


    for(int c = 1 ; c <= 8 ; c++) {
        if(!visited_col[c] && !right_diagonals[c+row] && !left_diagonals[8+c-row]) {
            col_place_in_row_used[row] = c ;

            visited_col[c] = right_diagonals[c+row] = left_diagonals[8+c-row] = 1 ;
            solve(row+1);
            visited_col[c] = right_diagonals[c+row] = left_diagonals[8+c-row] = 0 ;
        }
    }
}


int main() {
    //first we want to take the input
    int case_cnt = 1 ;
    while(cin >> col_place_in_row[1]) {
        col_place_in_row_used[1] = col_place_in_row[1] ;
        for(int i = 2 ; i <= 8 ; i++) {
            cin >> col_place_in_row[i] ;
            col_place_in_row_used[i] = col_place_in_row[i] ;
        }
        //we will start with the position of the first queen as if it is placed correctly in place
        //we will assign the place as visited
        solve(1);

        cout << "Case " << case_cnt << ": " << sum << endl;
        case_cnt++;
        sum = 999 ;

    }
}