#include <bits/stdc++.h>
using namespace std;

const int maxi = 505;
const int MOD = 1000000007;

int dp[maxi][maxi*(maxi+1)/2];

int main() {
    int n;
    cin >> n;

    memset(dp, 0, sizeof(dp));

    int sum = n * (n + 1) / 2;
    if (sum % 2 == 1) {
        cout << 0 << endl;
        return 0;
    } else {
        sum /= 2;

        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= i) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % MOD;
                }
            }
        }
    }

    cout << dp[n-1][sum] << endl;

    return 0;
}
