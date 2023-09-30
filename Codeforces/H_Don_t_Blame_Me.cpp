#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair

const int N = 2e5 + 5, mod = 1e9 + 7;

int power(int x, int y, int p){
    int res = 1;
    while(y){
        if(y&1) res = (res*x)%p;
        x = (x*x)%p;
        y >>= 1;
    }
    return res;
}

int T, n, k;
int a[N], cnt[1<<6];
int dp[1<<6], ans;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>T;

    while(T--){
        cin>>n>>k;
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }

        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++){
            cnt[a[i]]++;
        }

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 0; i < 64; i++){
            for(int mask = 0; mask < (1<<6); mask++){
                dp[mask&i] = (dp[mask&i] + power(2, cnt[i], mod)*dp[mask])%mod;
            }
        }

        ans = dp[k];
        cout<<ans<<endl;
    }

    return 0;
}
