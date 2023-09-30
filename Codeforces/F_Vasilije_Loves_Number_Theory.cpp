#include <iostream>
#include <vector>

using namespace std;

struct SegmentTree {
    vector<int> tree;
    int n;

    SegmentTree(int size) {
        n = 1;
        while (n < size) {
            n *= 2;
        }
        tree.resize(2 * n);
    }

    void reset(int index, int l, int r, int i) {
        if (l == r) {
            tree[index] = 1;
            return;
        }

        int mid = (l + r) / 2;
        if (i <= mid) {
            reset(2 * index + 1, l, mid, i);
        } else {
            reset(2 * index + 2, mid + 1, r, i);
        }

        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }

    void reset(int i) {
        reset(0, 0, n - 1, i);
    }

    int query(int index, int l, int r, int k) {
        if (l == r) {
            return l;
        }

        int mid = (l + r) / 2;
        if (tree[2 * index + 1] >= k) {
            return query(2 * index + 1, l, mid, k);
        } else {
            return query(2 * index + 2, mid + 1, r, k - tree[2 * index + 1]);
        }
    }

    int query(int k) {
        return query(0, 0, n - 1, k);
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> original_divisors(n + 1, 1);
        SegmentTree st(n + 1);

        for (int i = 2; i <= n; ++i) {
            for (int j = i; j <= n; j += i) {
                original_divisors[j]++;
            }
        }

        for (int i = 0; i < q; ++i) {
            int type;
            cin >> type;
            if (type == 1) {
                int x;
                cin >> x;
                int k = st.query(original_divisors[n]);
                if (k < n) {
                    cout << "YES\n";
                    st.reset(k);
                    n *= x;
                } else {
                    cout << "NO\n";
                }
            } else {
                st.reset(n);
                cin >> n;
            }
        }
    }

    return 0;
}
