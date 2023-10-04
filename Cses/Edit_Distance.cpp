#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int dp[5001][5001];

int solve(int i,int j, string& s1,string& s2){
    int n = s1.length();
    int m = s2.length();


    if(i==n || j==m){
        return abs(n-i) + abs(m-j);
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = INT_MAX;

    if(s1[i]!=s2[j]){
        
        int replace = 1+solve(i+1,j+1,s1,s2);
        int insert = 1+solve(i,j+1,s1,s2);
        int remove = 1+solve(i+1,j,s1,s2);
        ans = min(replace,min(insert,remove));

    }
    else{
        ans = solve(i+1,j+1,s1,s2);
    }

    return dp[i][j]=ans;
}


int main(){
    fast_io;
    string s1,s2;
    cin>>s1>>s2;

    memset(dp,-1,sizeof(dp));

    cout<<solve(0,0,s1,s2);

    return 0;
}
