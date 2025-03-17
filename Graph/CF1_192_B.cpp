 // created by MoniirMo
#include <bits/stdc++.h>
using namespace std;

char maze[1001][1001] ;
vector<pair<int,int>> monster_idx ;
vector<int> adj[1000004] ;
queue<int> q ;
vector<int> dist(1000004, 1000004);

void bfs(int u) {
    //we start by u as a source
    dist[u] = 0 ; q.push(u);
    int depth = 0 ; int sz = 1 ; int cur = u ;
    for(;!q.empty(); ++depth , sz = q.size()) {
        while(sz--) {
            cur = q.front() ; q.pop() ;
            for(int i = 0 ; i < adj[cur].size() ; i++) {
                if(dist[adj[cur][i]] == 1000004) {
                    dist[adj[cur][i]] = depth+1;
                    q.push(adj[cur][i]) ;
                }
            }
        }
    }
}


int main() {
    int r , c ;
    cin >> r >> c ;

    string holder ;
    int s , e ;
    for(int i = 1 ; i <= r ; i++) {
        cin >> holder ;
        for(int j = 1 ; j <= c ; j++) {
            int idx = j+(c*(i-1)) ;
            maze[i][j] = holder[j-1] ;
            if(maze[i][j] >= '1' && maze[i][j] <= '9') {
                monster_idx.push_back(make_pair(i,j)) ;
            }else if(maze[i][j] == 'S') {
                s = idx ;
            }else if(maze[i][j] == 'E') {
                e = idx ;
            }
        }
    }

    for(int i = 1 ; i <= r ; i++) {
        for(int j = 1 ; j <= c ; j++) {
            int idx = (j + (c*(i-1))) ;
            if(i == 1 && j == 1) {
                continue;
            }else if(i == 1) {
                //this means we are in the first row
                //so check first that the node is not a tree node
                if(maze[i][j] == 'T') continue ;
                //now we check for the past cell
                if(maze[i][j-1] == 'T') {
                    continue;
                }else {

                    adj[idx].push_back(idx-1);
                    adj[idx-1].push_back(idx) ;
                }
            }else if(j == 1) {
                //this means we are in the first col
                //so check first that the node is not a tree node
                if(maze[i][j] == 'T') continue ;
                //now we check for the upper cell
                if(maze[i-1][j] == 'T') {
                    continue;
                }else {
                    adj[idx].push_back(idx-c);
                    adj[idx-c].push_back(idx) ;
                }
            }else {
                //here we check for past and upper nodes
                if(maze[i][j] == 'T') continue ;
                if(maze[i][j-1] == 'T') {

                }else {
                    adj[idx].push_back(idx-1);
                    adj[idx-1].push_back(idx);
                }

                if(maze[i-1][j] == 'T') {

                }else {
                    adj[idx].push_back(idx-c);
                    adj[idx-c].push_back(idx);
                }
            }
        }
    }
    //now we have built the graph we should do a distance array to save the shortest path from a source to destination
    //we will make e as the source and for each node in monster is a destination
    bfs(e) ;
    int cnt = 0 ;
    for(int i = 0 ; i < monster_idx.size() ; i++) {
        int idx = (monster_idx[i].second + (c*(monster_idx[i].first-1))) ;
        if(dist[idx] <= dist[s]) {
             cnt += maze[monster_idx[i].first][monster_idx[i].second] - '0' ;
        }
    }
    cout << cnt ;
}
