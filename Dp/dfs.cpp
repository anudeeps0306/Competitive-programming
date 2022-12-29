#include<bits/stdc++.h>

using namespace std;


class Solution{
    void dfs(vector<int> adj[],int j,vector<int>& vist,vector<int>& ans){
        ans.push_back(j);
        vist[j] = 1;
        for(auto it : adj[j]){
            if(!vist[it]) dfs(adj,it,vist,ans);
        }
    }

    public:
        vector<int> dfsGraph(vector<int> adj[],int size){
            vector<int> vist(size+1,0);
            vector<int> ans;

            for(int i=1;i<size;i++){
                if(!vist[i]) dfs(adj,i,vist,ans);
            }

            return ans;
        }
};


void addEdge(vector<int> adj[],int edge,int vertex){
    adj[edge].push_back(vertex);
    adj[vertex].push_back(edge);
}


int main(){

    vector<int> adj[6];


    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,1,5);
    addEdge(adj,2,4);
    addEdge(adj,2,1);
    addEdge(adj,3,1);
    addEdge(adj,4,1);
    addEdge(adj,4,2);
    addEdge(adj,5,1);

    Solution obj;
    vector<int> ans = obj.dfsGraph(adj,6);
    for(auto it : ans) cout<<it<<" ";
    cout<<endl;

    return 0;
}