#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> input(n, vector<char>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> input[i][j];
            }
        }

        vector<vector<int>> left(m), up(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (input[i][j] == 'L') {
                    left[j].push_back(i);
                } else if (input[i][j] == 'U') {
                    up[i].push_back(j);
                }
            }
        }

        int ok = 1;
        for (const auto& l : left) {
            if (l.size() & 1) {
                ok = 0;
                break;
            }
        }
        for (const auto& u : up) {
            if (u.size() & 1) {
                ok = 0;
                break;
            }
        }

        if (!ok) {
            cout << -1 << '\n';
            continue;
        }

        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < left[j].size(); k += 2) {
                int i1 = left[j][k];
                int i2 = left[j][k + 1];
                input[i1][j] = 'W';
                input[i2][j] = 'B';
                input[i1][j + 1] = 'B';
                input[i2][j + 1] = 'W';
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < up[i].size(); k += 2) {
                int j1 = up[i][k];
                int j2 = up[i][k + 1];
                input[i][j1] = 'W';
                input[i][j2] = 'B';
                input[i + 1][j1] = 'B';
                input[i + 1][j2] = 'W';
            }
        }

        for (const auto& row : input) {
            for (char c : row) {
                cout << c;
            }
            cout << '\n';
        }
    }

    return 0;
}
