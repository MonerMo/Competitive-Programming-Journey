 //created by MoniirMo

#include <bits/stdc++.h>
using namespace std ;

vector<int> edges[100005] ;
bool visited[100005] ;



void dfs(int node) {
  if(visited[node]) return ;
  visited[node] = true  ;

 //now after marking visited we should loop for each adjacent node for the current node ;
 for(int i = 0 ; i < edges[node].size() ; i++) {
  //for each node traverse adjacent node
  dfs(edges[node][i]) ;
 }
}


int main() {


 int n , m ;
 cin >> n >> m ;

 for(int i = 1 ; i <= n ; i++) visited[i] = false ;


 //dfs using head node then loop on visited array for false values
 int a , b ;

 //traverse list

 for(int i = 0 ; i < m ; i++) {
  cin >> a >> b ;
  //because it is undirected graph so add it in both nodes
  edges[a].push_back(b);
  edges[b].push_back(a);
 }
 int head_node ;
 cin >> head_node ;

 dfs(head_node);
 int ans = 0 ;
 for(int i = 1 ; i <= n ; i++) if(!visited[i]) ans++ ;
 cout << ans << endl ;


}
