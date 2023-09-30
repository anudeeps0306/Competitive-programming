#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<int> g[N];
bool vis[N];

void dfs(int u, int v, unordered_set<int> &path) {
    if (u == v) {
        if (path.size() > 1) {
            cout << "Yes" << endl;
            exit(0);
        }
        return;
    }
    vis[u] = true;
    path.insert(u);
    for (int i = 0; i < g[u].size(); i++) {
        int to = g[u][i];
        if (!vis[to]) {
            dfs(to, v, path);
        }
    }
    vis[u] = false;
    path.erase(u);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= 2 * n; i++) {
            g[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int p;
                cin >> p;
                p += n;
                g[i].push_back(p);
                g[p].push_back(i);
            }
        }
        // checking if there's a path between two nodes
        // that goes through different set of nodes
        for (int i = 1; i <= 2 * n; i++) {
            for (int j = 0; j < g[i].size(); j++) {
                int to = g[i][j];
                if (to < i) {
                    unordered_set<int> path;
                    memset(vis, false, sizeof(vis));
                    dfs(i, to, path);
                }
            }
        }
        cout << "No" << endl;
    }
    return 0;
}
