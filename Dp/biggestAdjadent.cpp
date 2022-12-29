#include<bits/stdc++.h>

using namespace std;




int fa(vector<int> v,int n,vector<int>& dp){
    if(n == 0) return v[0];
    else if(n < 0) return 0;

    if(dp[n]!=-1) return dp[n];

    return dp[n]=max((v[n] + fa(v,n-2,dp)),fa(v,n-1,dp));
}

int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> dp(n,-1);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<fa(v,n-1,dp);
    return 0;
}