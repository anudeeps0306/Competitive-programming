#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_good(int x, const string& s) {
    int n = s.length();
    string l(n, '0');

    for (int i = 0; i < n; i++) {
        l[i] = (s[i] - '0') ^ ((x >> i) & 1);
    }

    for (int i = 0; i < n / 2; i++) {
        if (l[i] != l[n - 1 - i]) {
            return false;
        }
    }

    return true;
}
x
vector<int> find_good_numbers(const string& s) {
    int n = s.length();
    vector<int> good_numbers(n + 1, 0);

    for (int x = 0; x < (1 << n); x++) {
        if (is_good(x, s)) {
            int count_ones = __builtin_popcount(x);
            good_numbers[count_ones] = 1;
        }
    }

    return good_numbers;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> good_numbers = find_good_numbers(s);

        for (int i = 0; i <= n; i++) {
            cout << good_numbers[i];
        }

        cout << endl;
    }

    return 0;
}
