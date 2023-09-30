#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int mx[N], mn[N], cur[N], l1[N], l2[N], ctr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    mn[1] = 0;
    mx[1] = 1;
    cur[1] = 1;
    l1[1] = 1, l2[1] = 1;

    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;
        ctr = 2;
        while (q--) {
            char c;
            cin >> c;
            if (c == '+') {
                int l, r;
                cin >> l >> r;
                l1[ctr] = min(l1[l] + r, r);
                l2[ctr] = max(l2[l] + r, r);
                mx[ctr] = max({cur[l] + r, mx[l], l2[ctr]});
                mn[ctr] = min({cur[l] + r, mn[l], l1[ctr]});
                cur[ctr] = cur[l] + r;
                ctr++;
            } else {
                int l, r, k;
                cin >> l >> r >> k;
                cout << (mx[r] >= k && mn[r] <= k ? "YES\n" : "NO\n");
            }
        }
    }

    return 0;
}
