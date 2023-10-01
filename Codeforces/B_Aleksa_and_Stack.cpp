class Solution {
public:
    int dfs1(vector<vector<int>>& adj, vector<int>& values, vector<bool>& vist, int node, int k) {
    vist[node] = true;
    int cmp_sum = values[node];

    for (int neighbor : adj[node]) {
        if (!vist[neighbor]) {
            cmp_sum += dfs(adj, values, vist, neighbor, k);
        }
    }

    if (cmp_sum % k == 0) {
        return 0;
    } else {
        return cmp_sum;
    }
}

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        vector<vector<int>> adj(n);
        for (const vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vist(n, false);
        int mx_cmp = 0;
        
      
        function<int(int)> dfs = [&](int node) {
            vist[node] = true;
            int cmp_sum = values[node];
            
            for (int neighbor : adj[node]) {
                if (!vist[neighbor]) {
                    cmp_sum += dfs(neighbor);
                }
            }
            
            if (cmp_sum % k == 0) {
                mx_cmp++;
                return 0;
            } else {
                return cmp_sum; 
            }
        };
        
        for (int i = 0; i < n; ++i) {
            if (!vist[i]) {
               
                int cmp_sum = dfs(i);
                if (cmp_sum != 0) {
                    mx_cmp++;
                }
            }
        }
        
        return mx_cmp;
    }
};
