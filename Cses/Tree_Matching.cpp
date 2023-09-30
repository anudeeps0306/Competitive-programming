#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> adj[n + 1];
    vector<int> visited(n + 1, 0);

    for(int i = 1; i <= n; i++) { // Changed the loop start index to 1
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> leafNodes;

    for(int i = 1; i <= n; i++) {
        if(adj[i].size() == 1) {
            leafNodes.push_back(i);
        }
    }

    int cnt = 0;

    for(int i = 0; i < leafNodes.size(); i++) {
        int leafNode = leafNodes[i];
        if(!visited[leafNode] && !visited[adj[leafNode][0]]) {
            visited[leafNode] = 1;
            visited[adj[leafNode][0]] = 1;
            cnt++   ;
        }
    }

    cout << cnt << endl;

    return 0;
}
