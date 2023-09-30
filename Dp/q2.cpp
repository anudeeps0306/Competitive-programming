#include<bits/stdc++.h>
using namespace std;

const long long mod = (int)(1e9+7);



int main() {
    string s, s1 = "chokudai";
    cin >> s;

    vector<vector<int>> dp(s.size() + 1, vector<int>(s1.size() + 1, 0));

    for (int i = 0; i <= s.size(); i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= s1.size(); j++) {
            if (s[i - 1] == s1[j - 1]) {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout<<dp[s.size()][s1.size()]<<endl;
    return 0;
}
