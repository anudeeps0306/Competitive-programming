#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Function to calculate the greatest common divisor (GCD)
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<long long, long long>> points(n);
        unordered_map<pair<long long, long long>, int> directionCount;

        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }

        // Count the number of points in each direction from each point as the morning star
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    long long dx = points[j].first - points[i].first;
                    long long dy = points[j].second - points[i].second;
                    long long gcdValue = gcd(abs(dx), abs(dy));
                    dx /= gcdValue;
                    dy /= gcdValue;
                    directionCount[make_pair(dx, dy)]++;
                }
            }
        }

        long long totalPairs = 0;

        // Calculate the number of pairs that won't break the compass
        for (auto it = directionCount.begin(); it != directionCount.end(); it++) {
            long long count = it->second;
            totalPairs += count * (n - 1 - count);
        }

        cout << totalPairs / 2 << endl;
    }

    return 0;
}
