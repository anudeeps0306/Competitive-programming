#include <bits/stdc++.h>
using namespace std;


void dfs(vector<string> input,vector<vector<int>>& visit,int &count,int i,int j){
    visit[i][j]=1;
    count++;

    int nrow[] = {0,1,0,-1};
    int ncol[] = {1,0,-1,0};

    for(int m=0;m<4;m++){
        int krow = nrow[m]+i;
        int kcol = ncol[m]+j;
        if(krow>=0 && krow<input.size() && kcol>=0 && kcol<input[0].size() && !visit[krow][kcol] && input[krow][kcol]=='1'){
            dfs(input,visit,count,krow,kcol);
        }
    }
}

int main(){
	int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        // vector<vector<int>> v(n,vector<int>(m));
        vector<string> input;

        for(int i=0;i<n;i++){
            string in;
            cin>>in;
            input.push_back(in);
        }

        // for(int i=0;i<input.size();i++){
        //     for(int j=0;j<input[i].size();j++){
                
        //     }
        // }

        int count=0;
        vector<int> ans;
        vector<vector<int>> visit(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<!visit[i][j]<<"%"<<input[i][j]<<" ";
                if(visit[i][j]==0 && input[i][j]=='1'){
                    dfs(input,visit,count,i,j);
                    ans.push_back(count);
                    count=0;
                }
            }
            // cout<<endl;
        }

        sort(ans.begin(),ans.end(),greater<int>());
        long long a=0;

        for(int i =0;i<ans.size();i++){
            if(i%2==1){
                a+=ans[i];
            }
        }

        cout<<a<<endl;

    }
	return 0;
}