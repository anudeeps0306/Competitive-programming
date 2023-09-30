#include<bits/stdc++.h>

using namespace std;

long long mod = 1e9+7;

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> dp(m+1, INT_MAX);
    
    
    dp[0]=0;

    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            if(i>=a[j]){
                int ans = dp[i-a[j]];
                if(ans!=INT_MAX && ans+1<dp[i]){
                    dp[i]=ans+1;
                }
            }
        }
    }

 
    
    if(dp[m] == INT_MAX){
        cout<<-1<<endl;
    }
    else
        cout<<dp[m];

    return 0;
}