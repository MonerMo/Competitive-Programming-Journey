 // created by MoniirMo
#include <bits/stdc++.h>
using namespace std;

vector<int> edges[2505] ;
bool grid[51][51] ;
bool visited[2505] ;
bool visited_ans[2501] ;
vector<int>start_branch ;
vector<int>end_branch ;
int connected = 0 ;
int start_comp , end_comp ;
int s1 , s2 , e1 , e2 ;
int n ;

void dfs(int u) {
    if(visited[u]) return ;
    visited[u] = true ;
    int row = (u/n)+1 ;
    if(u%n==0) row-=1 ;
    int col = (u%n) ;
    if(col == 0) col = n ;

    if(row == s1 && col == s2) start_comp = connected ;
    if(row == e1 && col == e2) end_comp = connected ;

    //now loop for the remaining nodes connected to node u
    for(int i = 0 ; i < edges[u].size() ; i++) {
        dfs(edges[u][i]);
    }
}

void dfs_node(int u, int choice) {
    if(visited_ans[u]) return ;
    visited_ans[u] = true ;

    if(choice == 0) start_branch.push_back(u);
    if(choice == 1) end_branch.push_back(u);

    //now loop for the remaining nodes connected to node u
    for(int i = 0 ; i < edges[u].size() ; i++) {
        dfs_node(edges[u][i], choice);
    }
}



int main() {

    cin >> n ;

    //take start and end point as inputs please :)

    cin >> s1 >> s2 >> e1 >> e2 ;
    //cout << "s1= " << s1 << "  s2=" << s2 << "  ,e1" << e1 << "  ,e2" << e2 << endl;

    for(int i = 1 ; i <= n ; i++) {
        string input ;
        cin >> input ;
        for(int j = 1 ; j <= n ; j++) {
            grid[i][j] =  input[j-1] - '0' ;
        }
    }

    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            if(j == 1 && i == 1) {
                continue;
            }else if(i == 1) {
                if(grid[i][j] == grid[i][j-1]) {
                    int index = (n * (i-1)) + j ;
                    edges[index].push_back(index-1) ;
                    edges[index-1].push_back(index) ;
                }
            }else if(j == 1) {
                if(grid[i][j] == grid[i-1][j]) {
                    int index = ((n * (i-1)) + j) ;
                    edges[index].push_back(index-n) ;
                    edges[index-n].push_back(index) ;
                }
            }else {
                if(grid[i][j] == grid[i][j-1]) {
                    int index = ((n * (i-1)) + j) ;
                    edges[index].push_back(index-1) ;
                    edges[index-1].push_back(index) ;
                }

                if(grid[i][j] == grid[i-1][j]) {
                    int index = ((n * (i-1)) + j) ;
                    edges[index].push_back(index-n) ;
                    edges[index-n].push_back(index) ;
                }
            }
        }
    }

    //here we completed the connected components
    //we need to know how many connected components
    //if 1 then the output will be 0
    //if more than one we need to check where the start and end point allocated ( in which component )
    //if the same output 0
    //if not then we brute force on two components

    for(int i = 1 ; i <= n*n ; i++) {
        if(!visited[i]) {
            dfs(i);
            connected++;
        }
    }

    if(start_comp == end_comp) {
        //this means that they are in the same land
        cout << 0  ;
    }else {
        //dfs both components for the best output
        dfs_node((((s1-1)*n)+s2) , 0) ;
        dfs_node((((e1-1)*n)+e2) , 1) ;
        int ans = INT_MAX ;
        for(int i = 0 ; i < start_branch.size() ; i++) {
            int s1 , s2 ;
            s1 = (start_branch[i]/n)+1 ;
            if(start_branch[i]%n == 0) s1-=1 ;
            s2 = (start_branch[i]%n) ;
            if(s2 == 0) s2 = n ;

            for(int j = 0 ; j < end_branch.size() ; j++) {
                int e1 , e2 ;
                e1 = (end_branch[j]/n)+1 ;
                if(end_branch[j]%n == 0) e1-=1 ;
                e2 = (end_branch[j]%n) ;
                if(e2 == 0) e2 = n ;

                int holder = (s1-e1)*(s1-e1)+(s2-e2)*(s2-e2) ;
                if(ans > holder)
                    ans = holder ;
            }
        }
        cout << ans << endl;
    }


}
