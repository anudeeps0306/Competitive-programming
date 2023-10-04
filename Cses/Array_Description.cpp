#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(m + 1, 0));

    for (int i = 1; i <= m; ++i) {
        if (arr[0] == 0 || arr[0] == i) {
            dp[0][i] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i] == 0 || arr[i] == j) {
                dp[i][j] = dp[i - 1][j];
                if (j > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                if (j < m) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= m; ++i) {
        ans = (ans + dp[n - 1][i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}
