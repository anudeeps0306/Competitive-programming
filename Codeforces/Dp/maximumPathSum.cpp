#include<bits/stdc++.h>

using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n,vector<int>(m,0));

    for(int i=0;i<m;i++){
        dp[0][i] = matrix[0][i];
    }
    int ans = INT_MIN;
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int u = matrix[i][j] + dp[i-1][j];
            int ld = matrix[i][j];  
            if(j-1>=0) ld+=dp[i-1][j-1];
            else ld+=-1e8;
            int rd = matrix[i][j];
            if(j+1<m) rd+=dp[i-1][j+1];
            else rd+=-1e8;
            dp[i][j] = max(u,max(ld,rd));
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i=0;i<m;i++){
        ans = max(ans,dp[n-1][i]);
    }

    return ans;
}


int main(){

    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        vector<vector<int>> matrix(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>matrix[i][j];
            }
        }

        cout<<getMaxPathSum(matrix)<<endl;

    }
    return 0;
}