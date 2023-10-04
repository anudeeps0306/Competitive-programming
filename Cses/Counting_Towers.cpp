#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 1e6;
const int mod = 1e9 + 7;

int dp[maxn + 2][2];

void pre() {
    dp[maxn + 1][0] = 1;
    dp[maxn + 1][1] = 1;

    for (int i = maxn; i >= 2; i--) {
        dp[i][0] = ((2 * dp[i + 1][0]) % mod + dp[i + 1][0] + (dp[i + 1][0] + dp[i + 1][1]) % mod) % mod;
        dp[i][1] = ((dp[i + 1][0] + dp[i + 1][1]) % mod + dp[i + 1][1]) % mod;
    }
}

int32_t main() {
    int k;
    cin >> k;

    pre();

    while(k--){
        int n;
        cin>>n;
        cout << (dp[maxn-n+2][0] + dp[maxn-n+2][1]) % mod<<endl;
    }
    return 0;
}
