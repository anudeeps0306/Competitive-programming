#include<bits/stdc++.h>


using namespace std;

int a[200005];
int dist[200005];

void dfs(vector<int> adj[], int node,vector<int>& visited){
    int ans = 0;
    for(auto it : adj[node]){
        if(!visited[it]){
            visited[it] = 1;
            dfs(adj,it,visited);
            ans += dist[it] + 1;
        }
    }

    dist[node] = ans;
}



int main(){
    int n;
    cin >> n;

    vector<int> adj[n+1];   
    vector<int> visited(n+1);

    for(int i=2; i<=n;i++){
        int x;
        cin>>x;

        adj[x].push_back(i);
    }

    dfs(adj,1,visited);

    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;




    return 0;
}