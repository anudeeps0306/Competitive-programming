#include <bits/stdc++.h>
using namespace std;


const int MOD = (int)(1e9+7);

int main(){
    int n,x;
    cin>>n>>x;

    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    vector<int> dp(x+1,0);
    
    dp[0] = 1;
    for(int i=0;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-v[j]>=0){
                dp[i] += dp[i-v[j]];
                dp[i] %= MOD;
            }
        }        
    }

    cout<<dp[x]<<endl;
    return 0;
}