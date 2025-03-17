//
// Created by orabi on 11/27/2024.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> input(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> input[i] ;
    }

    vector<int> dp(sum+1,1e9);
    dp[0] = 0;
    for (int i = 1; i <= sum; i++) {
        for (int j = 0; j < n; j++) {
            if (i-input[j] >= 0) {
                dp[i] = min(dp[i], dp[i-input[j]]+1);
            }
        }
    }
    cout << (dp[sum] == 1e9 ? -1 : dp[sum]) << endl;
}