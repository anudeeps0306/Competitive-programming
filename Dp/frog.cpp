#include<bits/stdc++.h>

using namespace std;

const int N=1000000;

int dp[N];
int a[N];



int frog(int n){
    if(n==0) return 0;
    int cost = INT_MAX;
    cost = min(cost, frog(n-1)+abs(a[n]-a[n-1]));
    if(n>1)
    cost = min(cost, frog(n-2)+abs(a[n]-a[n-2]));
    return cost;
}





int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<frog(n-1);
    return 0;
}