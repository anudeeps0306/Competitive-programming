//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs(vector<vector<int>> grid,vector<vector<int>>& visit,int i,int j,vector<pair<int,int>>& k,int i0,int j0){
        visit[i][j] = 1;
        k.push_back({i0-i,j0});
        int row = grid.size();
        int col = grid[0].size();
        int rowl[] = {0,1,0,-1};
        int coll[] = {1,0,-1,0};
        
        for(int i=0;i<4;i++){
            int nrow = i + rowl[i];
            int ncol = j + coll[i];
            
            if(nrow>=0 && nrow<row && ncol>=0 && ncol<col && !visit[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(grid,visit,i,j,k,nrow,ncol);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> visit(row,vector<int>(col,0));
        set<vector<pair<int,int>>> s;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!visit[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>> k;
                    dfs(grid,visit,i,j,k,i,j);
                    s.insert(k);
                }
            }   
        }
        
        cout<<s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends