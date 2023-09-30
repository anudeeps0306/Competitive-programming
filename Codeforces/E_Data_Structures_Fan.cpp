#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        string s;
        cin >> s;

       
        vector<int> count0(n + 1, 0);
        vector<int> count1(n + 1, 0);

        for (int i = 0; i < n; i++) {
            cin >> a[i];

            // Update the count vectors based on the values in the binary string
            count0[i + 1] = count0[i] + (s[i] == '0');
            count1[i + 1] = count1[i] + (s[i] == '1');
        }

        int q;
        cin >> q;

        while (q--) {
            int tp;
            cin >> tp;

            if (tp == 1) {
                int l, r;
                cin >> l >> r;
                l--;
                r--;

                // Calculate the length of the substring
                int len = r - l + 1;

                // Toggle the characters in the binary string
                int zeros = count0[r + 1] - count0[l];
                int ones = count1[r + 1] - count1[l];
                count0[r + 1] += ones - zeros;
                count1[r + 1] += zeros - ones;
            } else {
                int g;
                cin >> g;

                // Calculate the answer based on the count vectors
                if (g == 0) {
                    cout << a[n] - a[count0[n]] << " ";
                } else {
                    cout << a[count1[n]] << " ";
                }
            }
        }

        cout << endl;
    }

    return 0;
}
