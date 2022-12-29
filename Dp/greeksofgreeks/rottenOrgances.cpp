//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int orangesRotting(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size(), res = 0;
		vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
		queue<int> q;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 2) q.push(i * n + j);
			}
		}
		while (!q.empty()) {
			++res;
			for (int i = q.size(); i > 0; --i) {
				int t = q.front(); q.pop();
				for (auto dir : dirs) {
					int x = t / n + dir[0], y = t % n + dir[1];
					if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1) continue;
					grid[x][y] = 2;
					q.push(x * n + y);
				}
			}
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 1) return -1;
			}
		} 
		return (res == 0) ? 0 : res - 1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends