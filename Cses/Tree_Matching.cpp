#include<bits/stdc++.h>
using namespace std;

int dp[200001][2];

int f(vector<int> adj[], int curr, int par, int isincluded) {
    int ans = 0;

    if(dp[curr][isincluded] != -1) {
        return dp[curr][isincluded];
    }

    if (isincluded) {
        int sum = 0;

        for (auto child : adj[curr]) {
            if (child != par) {
                sum += f(adj, child, curr, 1);
            }
        }

        for (auto child : adj[curr]) {
            if (child != par) {
                ans = max(ans, sum - f(adj, child, curr, 1) + f(adj, child, curr, 0) + 1);
            }
        }
    }
    else {
        for (auto child : adj[curr]) {
            if (child != par) {
                ans += max(f(adj, child, curr, 1), f(adj, child, curr, 0));
            }
        }
    }

    return dp[curr][isincluded]=ans;
}

int_fast32_t main() {
    int n;
    cin >> n;

    vector<int> adj[n + 1];

    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

   
    int result = max(f(adj, 1, -1, 0), f(adj, 1, -1, 1));

    cout << result << endl;

    return 0;
}
