//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


//time complexity is o(n) + o(v+2e)
//space complexity is o(n) + o(n)(for recurrsion stack)


// } Driver Code Ends
//User function Template for C++

class Solution {
    
private:
  void dfs(vector<int> adjlist[],vector<int>& visted,int i){
      visted[i]=1;
      
      for(auto it : adjlist[i]){
          if(visted[it]==0){
              dfs(adjlist,visted,it);
          }
      }
  }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjlist[V];
        
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        
        vector<int> visted(V+1,0);
        int count=0;
        for(int i=0;i<V;i++){
            if(visted[i]==0){
                count++;
                dfs(adjlist,visted,i);
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends