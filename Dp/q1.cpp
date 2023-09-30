#include<bits/stdc++.h>
using namespace std;

int f(vector<int>& v, int n, int prev, int position, vector<vector<int>>& memo) {
    if (position == n) return 0;

    if (memo[position][prev] != -1) {
        return memo[position][prev];
    }

    int ans = INT_MAX;
    if (v[position] == 0) {
        ans = min(ans, f(v, n, 0, position + 1, memo) + 1);
    } else if (v[position] == 1) {
        if (prev != 1) {
            ans = min(ans, f(v, n, 1, position + 1, memo));
        }
        ans = min(ans, f(v, n, 0, position + 1, memo) + 1);
    } else if (v[position] == 2) {
        if (prev != 2) {
            ans = min(ans, f(v, n, 2, position + 1, memo));
        }
        ans = min(ans, f(v, n, 0, position + 1, memo) + 1);
    } else if (v[position] == 3) {
        if (prev != 1 && prev != 3) {
            ans = min(ans, f(v, n, 1, position + 1, memo));
        }
        if (prev != 2 && prev != 3) {
            ans = min(ans, f(v, n, 2, position + 1, memo));
        }
        ans = min(ans, f(v, n, 0, position + 1, memo) + 1);
    }

    return memo[position][prev] = ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    vector<vector<int>> memo(n, vector<int>(4, -1));

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << f(v, n, 0, 0, memo) << endl;
    return 0;
}
