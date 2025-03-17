 //created by MoniirMo

#include <bits/stdc++.h>
using namespace std ;

//we need to have an array of a vector of pairs
vector<pair<int,int>> edges[100005] ;
bool status[100005] ;
vector<int>delete_candidates ;

short dfs(int u , int resp) {
    //so the magic happens here
    //0 for it respects , 1 for it doesn't respect , 2 for it doesn't respect and delete it
    //we keep dfs and have a condition for leaves to kill them or not
    if(!resp){
        //this means that the node respect its parents go check its childs
        for(int i = 0 ; i < edges[u].size() ; i++) {
            pair<int,int> holder = edges[u][i] ;
            dfs(holder.first, holder.second);
        }
        return 0 ;
    }else if(edges[u].size() == 0 && resp) {
        //this means that it have no childs and don't respect its parents
        delete_candidates.push_back(u);
        return 2 ;
    }else {
        //this means this node is not a leaf and does not respect it's parents
        bool really = false ;
        for(int i = 0 ; i < edges[u].size() ;) {
            //for each of its child if one return true this means it respects
            pair<int,int> holder = edges[u][i] ;
            short status_holder = dfs(holder.first, holder.second);
            if(status_holder == 2) {
                //we want to delete the current pair
                edges[u].erase(edges[u].begin() + i);
            }else {
                i++ ;
                if(status_holder == 0) really = true ;
            }
        }

        //here we will decide if the current node is not a leaf and a candidate to delete or not
        if(really) {
            //this means it is not a candidate
            return 1 ;
        }else {
            delete_candidates.push_back(u);
            return 2 ;
        }
    }
}


int main() {
    int nodes ;
    cin >> nodes ;

    int parent , respect , root = 0 ;
    for(int i = 1 ; i <= nodes ; i++) {
        cin >> parent >> respect ;

        //in case that we reached a node and its parent is -1 this means that it is the root node
        if(parent == -1) {
            status[i] = false ;
            root = i ;
            continue ;
        }
        //here I add the child to the parent
        edges[parent].emplace_back(i,respect) ;
        status[i] = respect ;
    }

    //now after taking the input we need to traverse each node and check for the possibility to delete
    //so after that we keep deleting the nodes in the candidates vector , and keep doing this till it is empty

    dfs(root, 0);
    //now after removing the none respecting leaves and coloring the candidates
    if(delete_candidates.size()) {
        sort(delete_candidates.begin(), delete_candidates.end()) ;
        for(int x : delete_candidates) cout << x << " " ;
    }else {
        cout << -1 ;
    }
}
