#include<bits/stdc++.h>

using namespace std;

const int N=1000000;

int dp[N];

int fibc(int n){
    if(n==0){
        return 0;
    }
    else if(n==1) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fibc(n-1) + fibc(n-2);
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    cout<<fibc(n)<<endl;
    return 0;
}