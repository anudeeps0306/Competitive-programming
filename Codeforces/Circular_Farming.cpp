#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
const double EPS = 1e-9;

int T, n;
int ULx, ULy, LRx, LRy, Dx, Dy;
double max_radius;
bool visited[N];
vector<pair<int, int>> trees;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool is_valid_circle(int x, int y, double radius) {
    if (x - radius < ULx || x + radius > LRx || y - radius < LRy || y + radius > ULy) {
        return false; // circle is out of bounds
    }
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        double d = dist(x, y, trees[i].first, trees[i].second);
        if (d - radius < -EPS) return false; // circle intersects with the tree
    }
    return true;
}

int count_good_circles() {
    int ans = 0;
    memset(visited, false, sizeof visited);
    for (double r = max_radius; r >= 0.0; r -= 1.0) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            double d = dist(Dx, Dy, trees[i].first, trees[i].second);
            if (d - r < -EPS) { // tree is inside the circle
                visited[i] = true;
                cnt++;
            }
        }
        if (cnt == n) return ans; // all trees are inside a circle
        for (int i = Dx - (int)r; i <= Dx + (int)r; i++) {
            for (int j = Dy - (int)r; j <= Dy + (int)r; j++) {
                if (is_valid_circle(i, j, r)) {
                    ans++;
                }
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> ULx >> ULy >> LRx >> LRy >> Dx >> Dy >> n;
        max_radius = max({dist(Dx, Dy, ULx, ULy), dist(Dx, Dy, LRx, LRy), dist(Dx, Dy, ULx, LRy), dist(Dx, Dy, LRx, ULy)});
        trees.clear();
        for (int i = 0; i < n; i++) {
            int x, y;
            double r;
            cin >> x >> y >> r;
            trees.push_back({x, y});
        }
        cout << "Case " << t << ": " << count_good_circles() << "\n";
    }
    return 0;
}
