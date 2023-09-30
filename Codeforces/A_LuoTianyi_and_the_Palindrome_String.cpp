#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        bool flag = false;
        for (int i = 0; i < n && !flag; i++) {
            for (int j = n - 1; j > i; j--) {
                if (s[i] != s[j]) {
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) {
            cout << "-1\n";
        } else {
            cout << n-1 << "\n";
        }
    }
    return 0;
}
