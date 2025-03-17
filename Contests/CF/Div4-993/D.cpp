//
// Created on 12/15/2024.
//
//created by MoniirMo
#include <bits/stdc++.h>
using namespace std ;
int freq[200002] ;
int mode[200002] ;
int main() {
    int t;
    cin >> t ;
    while(t--) {
        int sz ;
        cin >> sz ;
        vector<int>input(sz) ;
        for(int i = 0 ; i < sz ; i++) {
            cin >> input[i] ;
        }
        //so we always should keep track of the max mode with us
        //start normally by putting the first element
        vector<int> ans;
        int highest_mod = 0 ;
        ans.push_back(input[0]);
        freq[input[0]]++;
        mode[0]++ ;

        for(int i = 1 ; i < sz ; i++) {
            //I check my own frequency
            mode[i] += mode[i-1] ;
            if(freq[input[i]] + 1 >= freq[input[i-1]]) {
                //here I am checking if i placed my self in the current position I am good or not
                ans.push_back(input[i]) ;
                freq[input[i]]++;
                //each time we need to check if the freq of the current number is bigger than the past mode
                if(freq[input[i]] > mode[i])
                    mode[i] = freq[input[i]] ;
            }else if(freq[input[i]] + 1 < freq[input[i-1]]) {
                //first we will suppose we added our current number to the list
                freq[input[i]]++ ;
                int pop_count = 0 ;
                int index = i ;
                while(index >= 0) {
                    //now we go backwards
                    if(freq[input[index-1]]-1 == freq[input[i]]) {
                        //this means by removing the past only and put dummy val
                        //we are good and insert dummy value
                        freq[input[index-1]]--;
                        ans.pop_back();
                        ans.push_back(200001);
                        freq[200001]++;
                        for(int idx = 0 ; idx <= pop_count ; idx++) {
                            ans.push_back(input[i]);
                            freq[input[i]]++;
                        }
                        break;
                    }else if(freq[input[index-1]]-1 == freq[input[i]]+1) {
                        freq[input[index-1]]--;
                        ans.pop_back();
                        for(int idx = 0 ; idx <= pop_count ; idx++) {
                            ans.push_back(input[i]);
                            freq[input[i]]++;
                        }
                        break;
                    }else {
                        freq[input[index-1]]--;
                        ans.pop_back();
                        pop_count++;
                        //ans.push_back(input[i]);
                        freq[input[i]]++;
                        index--;
                    }
                }
            }
        }

        for(int x : ans)
            cout << x << " " ;
        cout << endl;
    }
}
