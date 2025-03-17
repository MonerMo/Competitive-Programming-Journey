//
// Created by orabi on 11/21/2024.
//
#include <bits/stdc++.h>

using namespace std ;


vector<unsigned long long> lucky_nums ;

void lucky(unsigned long long l , unsigned long long r, unsigned long long past_gen) {
    //we want to stop at each branch if we reached a lucky number greater than r
    if(past_gen > r){
        lucky_nums.push_back(past_gen);
        return ;
    }else if(past_gen < l) {
        lucky(l, r,((past_gen*10) + 4));
        lucky(l, r, ((past_gen*10) + 7));
    }else {
        lucky_nums.push_back(past_gen);
        lucky(l, r,((past_gen*10) + 4));
        lucky(l, r, ((past_gen*10) + 7));
    }

}

int main() {

    long long l , r ;
    long long sum = 0 ;
    cin >> l >> r ;

    lucky(l, r,0);
    sort(lucky_nums.begin(), lucky_nums.end());
    //for(auto x : lucky_nums) cout << x << " " ;
    //cout << endl;
    long long sz = static_cast<long long>(lucky_nums.size()) ;
    for(int i = 0 ; i < sz; i++) {
        if(lucky_nums[i] > r) {
            //cout << "catch it: " << lucky_nums[i] << endl;
            //cout << "current sum:" << sum << endl;
            if(i==0) {
                sum = ( r-l+1 ) * lucky_nums[0] ;
                break;
            }
            sum += ((r-lucky_nums[i-1]) * lucky_nums[i]) ;
            break;
        }
        if(i == 0) {
            sum += (lucky_nums[0] - l + 1) * lucky_nums[0] ;
        }else {
            sum += (lucky_nums[i] - lucky_nums[i-1]) * lucky_nums[i] ;
        }

    }
    cout << sum << endl;

}