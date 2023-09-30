#include <bits/stdc++.h>
using namespace std;


const int MOD = (int)(1e9+7);
 
int main(){
    int n,m;
    cin>>n>>m;

    vector<int> a(n),b(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    vector<int> dp(m+1,0);
    

    int maxi = 0;
    for(int i=0;i<n;i++){
        for(int j=m;j>=a[i];j--){
            dp[j] = max(dp[j],dp[j-a[i]]+b[i]);
            maxi = dp[j];
        }
    }

    cout<<dp[m]<<endl;
    
    return 0;
}