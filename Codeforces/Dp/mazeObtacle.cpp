#include <bits/stdc++.h>
using namespace std;

const int mod = (int)10e9+7;

int maze(int n,int m,vector<vector<int>> a){
    vector<vector<int>> dp(n,vector<int>(m,-1));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0) dp[i][j]=1;
            else if(i>=0 && j>=0 && a[i][j]==-1) dp[i][j]=0;
            else{
                int up=0,down=0;
                if(i>0){
                    up = dp[i-1][j];
                }
                if(j>0)  down = dp[i][j-1];
                dp[i][j] = (up+down)%mod;
            }
        }
    }
    return dp[n-1][m-1];
}
 
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    cout<<maze(n,m,a);
    return 0;
}