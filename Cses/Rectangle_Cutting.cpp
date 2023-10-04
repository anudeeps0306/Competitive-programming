#include<bits/stdc++.h>


using namespace std;

int dp[501][501];

int f(int n,int m){

    if(n==m) return 0;

    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    int v = INT_MAX,h=INT_MAX;

    for(int i=1;i<n;i++){
        v = min(v,1+f(i,m)+f(n-i,m));
    }

    for(int i=1;i<m;i++){
        h = min(h,1+f(n,i)+f(n,m-i));
    }

    return dp[n][m]=min(v,h);
}


int main(){
    int n,m;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    cout<<f(n,m);
    return 0;
}