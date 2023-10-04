#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n, c;
    cin >> n >> c;

    vector<ll> v(n);

    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }

    ll limit = 1 << n;

    vector<pair<ll, ll>> dp(limit, {LLONG_MAX, LLONG_MAX}); // Initialize with large values

    dp[0] = {0, 0}; // Initialize with 0 rides and 0 total cost

    for (int i = 1; i < limit; i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
               
                pair<ll, ll> prev_state = dp[i ^ (1 << j)];

                if (prev_state.second + v[j] <= c) {
                  
                    prev_state.second += v[j];
                } else {

                    prev_state.first++;
                    prev_state.second = v[j];
                }

                dp[i] = min(dp[i], prev_state);
            }
        }
    }

    cout << dp[limit - 1].first + 1 << endl;

    return 0;
}
