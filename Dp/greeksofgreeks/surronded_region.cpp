//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    void dfs(vector<vector<char>> mat,vector<vector<int>>& visit,int n,int m){
        int nrow[] = {0,1,0,-1};
        int ncol[] = {1,0,-1,0};
        
        int row = mat.size();
        int col = mat[0].size();
        
        for(int i=0;i<4;i++){
            int krow = n + nrow[i];
            int kcol = m + ncol[i];
            if(krow>=0 && krow<row && kcol>=0 && kcol<col && mat[krow][kcol] == 'O'){
                visit[krow][kcol] = 1;
                dfs(mat,visit,krow,kcol);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        vector<vector<int>> visit(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            if(mat[i][0] == 'O' && !visit[i][0]){
                dfs(mat,visit,i,0);
            }
            if(mat[i][m-1] == 'O' && !visit[i][m-1]){
                dfs(mat,visit,i,m-1);
            }
        }
        
        for(int j=0;j<m;j++){
            if(mat[0][j] == 'O' && !visit[0][j]){
                dfs(mat,visit,0,j);
            }
            if(mat[n-1][j] == 'O' && !visit[0][j]){
                dfs(mat,visit,n-1,j);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 'O' && !visit[i][j]){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends