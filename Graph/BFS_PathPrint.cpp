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
    vector<int> parent(n,-1); //-1 means the node not visited
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
                    parent[adj[cur][i]] = cur ;
                }
                q.push(adj[cur][i]) ;
            }
        }
    }

    //let us say we want to print the shortest path from the source to node = 4
    int node = 3 ;
    vector<int> output ;
    while(node != -1) {
        output.push_back(node) ;
        node = parent[node] ;
    }
    sort(output.begin(), output.end()) ;
    for(int holder : output) cout << holder << " " ;
}
