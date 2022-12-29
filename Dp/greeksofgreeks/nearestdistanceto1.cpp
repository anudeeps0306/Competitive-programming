//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid){
	    int row = grid.size();
	    int col = grid[0].size();
	    vector<vector<int>> ans(row,vector<int>(col,0));
	    vector<vector<int>> visit(row,vector<int>(col));
	    queue<pair<pair<int,int>,int>> q;
	    
	    for(int i=0;i<row;i++){
	        for(int j=0;j<col;j++){
	            if(grid[i][j] == 1){
	                q.push({{i,j},0});
	                visit[i][j] = 1;
	            }
	            else{
	                visit[i][j] = 0;
	            }
	        }
	    }
	    
	    int lrow[] = {1,0,-1,0};
	    int lcol[] = {0,1,0,-1};
	    
	    
	    while(!q.empty()){
	        int nrow = q.front().first.first;
	        int ncol = q.front().first.second;
	        int dis = q.front().second;
	        
	        ans[nrow][ncol] = dis;
	        
	        q.pop();
	        
	        for(int i =0 ;i<4;i++){
	            int krow = nrow + lrow[i];
	            int kcol = ncol + lcol[i];
	            
	            if(krow>=0 && krow<row && kcol>=0 && kcol<col && visit[krow][kcol] == 0){
	                visit[krow][kcol] = 1;
	                q.push({{krow,kcol},dis+1});
	            }
	        }
	}
	
	return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends