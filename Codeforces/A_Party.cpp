#include<bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
const ll N= 2e5+10,inf =1e18;


vector<int>adj[N];
int vis[N];
int ans=1;
void dfs(int node,int depth)
{
    ans=max(ans,depth);
    for(auto child:adj[node])
    {
        if(!vis[child])
        {
            vis[child]=1;
            dfs(child,depth+1);
        }
    }
}
int main() {
    FIO
  int n;
    cin>>n;
    vector<int>v;
    int p;
    for(int i=1;i<=n;i++)
    {
        cin>>p;
        if(p==-1)v.push_back(i);
        else
        adj[p].push_back(i);
    }
    for(auto it:v)
    {
        dfs(it,1);
    }
    cout<<ans<<'\n';
    return 0;
}