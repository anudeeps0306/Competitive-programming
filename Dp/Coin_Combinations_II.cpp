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
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            if (j - v[i - 1] >= 0) {
				dp[j] += dp[j - v[i - 1]];
				dp[j] %= MOD;
			}
        }        
    }

    cout<<dp[x]<<endl;
    return 0;
}