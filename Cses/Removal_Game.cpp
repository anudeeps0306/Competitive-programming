#include <bits/stdc++.h>
using namespace std;

int dp[5001][5001];

int f(vector<int> &v, int start, int end) {
    if (start > end) {
        return 0;
    }

    if (dp[start][end] != -1) {
        return dp[start][end];
    }

    int val1 = min(f(v, start + 1, end - 1), f(v, start + 2, end)) + v[start];
    int val2 = min(f(v, start, end - 2), f(v, start + 1, end - 1)) + v[end];

    return dp[start][end]=max(val1, val2);
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << f(v, 0, n - 1) << endl;

    return 0;
}
