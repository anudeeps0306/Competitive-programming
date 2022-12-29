//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    void dfs(int row,int col, vector<vector<int>> &visit, vector<vector<char>>  grid){
        visit[row][col] = 1;
        
        int row_  = grid.size();
        int col_ = grid[0].size();
        
        for(int drow = -1 ; drow<=1 ; drow++){
            for(int dcol = -1 ; dcol<=1 ;dcol++){
                int lrow = row + drow;
                int lcol = col + dcol;
                
                if(lrow>=0 && lrow<row_ && lcol>=0 && lcol<col_ && visit[lrow][lcol]!=1 && grid[lrow][lcol]=='1'){
                    dfs(lrow,lcol,visit,grid);
                }
            }
        }
    } 
  
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> visit(row , vector<int>(col,0));
        int cnt=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cnt++;
                dfs(row,col,visit,grid);
            }
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends