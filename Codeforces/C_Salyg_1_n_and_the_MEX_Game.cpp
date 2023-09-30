#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> s(n);

        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        set<int> unique_s(s.begin(), s.end());
        int mex = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == mex) {
                mex++; 
            } else if (s[i] < mex) {
                cout << s[i] << endl;
                cout.flush();
                cin >> s[i];
                i--;
            } else {
                cout << mex << endl;
                cout.flush();
                mex++;
                cin >> s[i];
                i--;
            }
        }

       
        while (n < 2 * n + 1) {
            cout << mex << endl;
            cout.flush();
            cin >> s[n];
            n++;
        }

        cout << -1 << endl;
        cout.flush();
    }

    return 0;
}
