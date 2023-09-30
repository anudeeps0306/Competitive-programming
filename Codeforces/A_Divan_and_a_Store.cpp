#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        bool found = false;
        double x, y;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            if (!found && k != 0) { 
                for (int j = 0; j < m; j++) {
                    int a, b, c;
                    cin >> a >> b >> c;
                    double distance = abs(c - b*b*1.0/(4*a));
                    double threshold = abs(a * sqrt(distance));
                    double vertex_x = -b*1.0/(2*a);
                    if (k > threshold || k < -threshold) {
                      
                        found = true;
                        x = k;
                        y = 0;
                        break;
                    }
                }
            }
            else {
    
                string line;
                getline(cin, line);
            }
        }
        for (int i = 0; i < m; i++) {
            cout << (found ? "YES\n" : "NO\n");
            if (found) {
                cout << x << endl;
            }
        }
    }
    return 0;
}
