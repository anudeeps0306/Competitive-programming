#include <iostream>
#include <vector>

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

        int mex = 0;
        int lastAdded = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] > mex) {
                cout << mex << endl;
                lastAdded = mex;
                cin >> s[i]; // Bob removes an element
            } else {
                cout << s[i] << endl; // Alice adds the next smallest number from the set
                lastAdded = s[i];
                cin >> s[i]; // Bob removes an element
            }

            if (lastAdded == mex) {
                mex++; // Update MEX
            }
        }

        // Continue adding numbers until 2n+1 moves are completed
        while (n < 2 * n + 1) {
            cout << mex << endl;
            cin >> s[n]; // Bob removes an element
            n++;
        }

        cout << -1 << endl; // End of the game
    }

    return 0;
}
