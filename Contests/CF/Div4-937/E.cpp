//
// Created by orabi on 3/28/2024.
//
#include <bits/stdc++.h>

using namespace std ;

int main(){

    int t;
    cin >> t ;

    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        int similar = 0;
        int diff = 0;
        int great = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > great) great = freq[i];
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] == great) {
                similar++;
            }else if(freq[i] != great && freq[i] > 0) {
                diff++;
            }
        }

        cout << similar << " " << diff << endl;
        for(int x : freq)
            cout << x << " " ;
        cout << endl;

        if (similar > 0 && diff == 0) {
            bool flag = true;
            for (int i = 1; i < n; i++) {
                if (s[i] == s[i - 1]) {
                    flag = false;
                    cout << n << endl;
                    break;
                }
            }
            if (flag) cout << similar << endl;
        }else if(similar > 0 && diff == 2) {
            cout << similar + 1 << endl;
        }else if(similar > 0 && diff == 1 && n%2 == 0){
            cout << 1 << endl;
        }else{
            cout << n << endl;
        }
    }
}