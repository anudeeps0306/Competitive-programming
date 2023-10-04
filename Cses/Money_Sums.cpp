#include <bits/stdc++.h>
using namespace std;
int dp[100000][100];

int f(int sum, int pos, vector<int>& v, set<int>& ans) {
    if (pos == v.size()) {
        ans.insert(sum);
        return sum;
    }
    if (dp[sum][pos] != -1) {
        return dp[sum][pos];
    }


    int sum1 = f(sum + v[pos], pos + 1, v, ans);
    int sum2 =f(sum, pos + 1, v, ans);

    return dp[sum][pos] = max(sum1, sum2);

}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    set<int> ans;

    f(0, 0, v, ans);

    cout << ans.size() - 1 << endl;

    int cnt = 0;
    for (auto it : ans) {
        if (cnt != 0)
            cout << it << " ";
        cnt++;
    }

    cout << endl;

    return 0;
}
