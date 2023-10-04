#include <bits/stdc++.h>
using namespace std;



int main() {
    long long n;
    cin >> n;

    vector<tuple<long long, long long, long long>> v(n);

    for (long long i = 0; i < n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        v[i] = {b, a, c};
    }

    sort(v.begin(), v.end());

    long long sum = 0;

    map<long long, long long> dp; // (end: sum)

    dp[0] = 0;

    for (auto it : v) {
        long long start = get<1>(it);
        long long end = get<0>(it);
        long long cost = get<2>(it);

        auto it1 = dp.lower_bound(start);

        if (it1 != dp.begin()) {
            it1--;

            long long max_sum = it1->second + cost;
            sum = max(sum, max_sum);
        }

        dp[end] = sum;
    }

    cout << sum << endl;

    return 0;
}
