#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 5;

vector<int> adj[MAX_N];
int max_distance;
int farthest_node;

void dfs(int node, int parent, int depth) {
    if (depth > max_distance) {
        max_distance = depth;
        farthest_node = node;
    }

    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node, depth + 1);
        }
    }
}

int find_diameter(int n) {
    max_distance = -1;
    dfs(1, -1, 0);
    int node1 = farthest_node;

    // cout<<node1<<endl;

    max_distance = -1;
    dfs(node1, -1, 0);
    int node2 = farthest_node;

    // cout<<node2<<endl;

    return max_distance;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int diameter = find_diameter(n);
    cout << diameter << endl;

    return 0;
}
