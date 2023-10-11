#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 998244353;

long long solve(int n, std::vector<int>& a) {
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = (ans + a[i]) % MOD;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = i; j < n; j += i) {
            a[j] = std::max(a[j], a[i - 1]);
        }
    }

    std::sort(a.begin(), a.end(), std::greater<int>());

    for (int i = 0; i < n - 1; ++i) {
        ans = (ans + ((a[i] * (1LL << i)) % MOD)) % MOD;
    }

    return ans;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    long long result = solve(n, a);
    std::cout << result << std::endl;

    return 0;
}
