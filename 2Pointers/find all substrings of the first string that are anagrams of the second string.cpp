#include <bits/stdc++.h>

using namespace std ;

int main() {


    //input string = "XYYZXZYZXXYZ" , second input string "YZX"
    /*
     * output :
     * YZX i =2 , XZY i = 4 , YZX i = 6 , XYZ i = 9 ;
     */

    /*
     * better idea here is to move right character by character and check from the index of the character to
     * index + size of the second string , and compare if the window size in the input string
     * with size (index , index + size of the second string ) is an anagram of the second string or not
     * you can use unordered_multiset in order to maintain
     */
    string first = "XYYZXZYZXXYZ" ;
    string second = "YZX" ;

    int first_sz = first.size() , second_sz = second.size() ;
    int low = 0 , high = 0 + second_sz - 1;

    //remember that unordered multiset or multiset can hold the input of having duplicates of one element
    //not like unordered set and set that can't handle the duplicates of one element
    unordered_multiset<char>sec ;
    for(int i = 0 ; i < second_sz ; i++){
        sec.emplace(second[i]);
    }

    unordered_multiset<char>window ;


    for(int i = 0 ; i < first_sz ; i++){
        //now we want to insert first m letters in the window
        if(i < second_sz){
            window.emplace(first[i]);
        }else{
            //this means that we have the size of the window and ready to compare
            if(window == sec){
                cout << "Anagram : " << first.substr(i-second_sz , second_sz)
                << " at index = " << i-second_sz << endl;
            }

                //after testing and taking the first window of size second_sz now
                //we want to take the second window in order to test it
                //in this case we want to delete the most left character
                //and we want to insert one more character from the right.

                //we want to get an iterator the location of the left most letter
                auto itr = window.find(first[i-second_sz]);
                //now we will delete/remove it from the set
                if(itr != window.end())
                    window.erase(itr);

                //now we will add the new letter
                window.insert(first[i]);
        }
    }

    //one more comparison will remain is to compare the last permutation
    if(window == sec){
        cout << "Anagram : " << first.substr(first_sz - second_sz  , second_sz) << "at index = "
        << first_sz - second_sz << endl ;
    }
}
