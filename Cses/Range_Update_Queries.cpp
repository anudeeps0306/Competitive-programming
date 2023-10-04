#include <bits/stdc++.h>
using namespace std;

#define int long long

class segmentTree {
    vector<int> st, lazy;

public:
    segmentTree(int n) {
        st.resize(4 * n); // Initialize the segment tree array to store values
        lazy.resize(4 * n); // Initialize the lazy propagation array
    }

    void build(int ind, int low, int high, int arr[]) {
        if (low == high) {
            st[ind] = arr[low]; // Assign value from the array to the leaf node
            return;
        }
        int mid = (low + high) >> 1; // Calculate the middle index
        build(2 * ind + 1, low, mid, arr); // Build left subtree
        build(2 * ind + 2, mid + 1, high, arr); // Build right subtree
        st[ind] = st[2 * ind + 1] + st[2 * ind + 2]; // Update the current node's value
    }

    void propagate(int ind, int low, int high) {
        if (lazy[ind] != 0) {
            st[ind] += (high - low + 1) * lazy[ind]; // Update the node value with lazy propagation
            if (low != high) {
                lazy[2 * ind + 1] += lazy[ind]; // Propagate to left child
                lazy[2 * ind + 2] += lazy[ind]; // Propagate to right child
            }
            lazy[ind] = 0; // Reset the current node's lazy value
        }
    }

    void update(int ind, int low, int high, int l, int r, int val) {
        propagate(ind, low, high); // Update current node with pending lazy values

        if (high < l || r < low) {
            return; // No overlap, no need to update
        }

        if (low >= l && high <= r) {
            st[ind] += (high - low + 1) * val; // Update current node within the range
            if (low != high) {
                lazy[2 * ind + 1] += val; // Propagate to left child
                lazy[2 * ind + 2] += val; // Propagate to right child
            }
            return;
        }

        int mid = (low + high) >> 1; // Calculate the middle index
        update(2 * ind + 1, low, mid, l, r, val); // Update left subtree
        update(2 * ind + 2, mid + 1, high, l, r, val); // Update right subtree

        st[ind] = st[2 * ind + 1] + st[2 * ind + 2]; // Update current node's value
    }

    int query(int ind, int low, int high, int l, int r) {
        propagate(ind, low, high); // Update current node with pending lazy values

        if (high < l || r < low) {
            return 0; // No overlap, return neutral value
        }

        if (low >= l && high <= r) {
            return st[ind]; // Node's value contributes to the result
        }

        int mid = (low + high) >> 1; // Calculate the middle index
        int left = query(2 * ind + 1, low, mid, l, r); // Query left subtree
        int right = query(2 * ind + 2, mid + 1, high, l, r); // Query right subtree
        return left + right; // Combine the results from left and right subtrees
    }
};

int32_t main() {
    int n, m;
    cin >> n >> m;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    segmentTree st(n); // Create a segment tree object
    st.build(0, 0, n - 1, arr); // Build the segment tree using the input array

    while (m--) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b, val;
            cin >> a >> b >> val;
            st.update(0, 0, n - 1, a - 1, b - 1, val);
        } else {
            int k;
            cin >> k;
            cout << st.query(0, 0, n - 1, k - 1, k - 1) << endl;
        }
    }

    return 0;
}
