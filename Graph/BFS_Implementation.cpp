 // created by MoniirMo
#include <bits/stdc++.h>
using namespace std;

int main() {



    int n , m ;
    cin >> n >> m ;
    //n nodes , m edges
    vector<int> adj[100];
    int x , y ;
    for(int i = 0 ; i < m ; i++) {
        cin >> x >> y ;
        adj[x].push_back(y);
    }
    //taking the root of the graph
    int root ;
    cin >> root ;
    //now after taking the input , calculate the length for each node
    vector<int> distance(n+1,10000);//10000 should be large enough larger than or equal to the largest possible path
    queue<int> q ;
    distance[root] = 0 ;
    q.push(root) ;
    int depth = 0 , sz = 1 , cur = root ;
    for(;!q.empty(); ++depth , sz = q.size()) {
        //here we need to take the next node to process
        cur = q.front() ; q.pop() ;
        while(sz--) {
            for(int i = 0 ; i < adj[cur].size() ; i++) {
                if(distance[adj[cur][i]] == 10000) {
                    //this means we didn't reach this node yet
                    distance[adj[cur][i]] = depth + 1 ;
                }
                q.push(adj[cur][i]) ;
            }
        }
    }

    //now print each node with the shortest path to it
    for(int i = 1 ; i <= n ; i++) {
        cout << "node : " << i << " , Path length : " << distance[i] << endl;
    }
}
