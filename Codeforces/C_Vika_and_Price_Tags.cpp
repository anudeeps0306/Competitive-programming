#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string isDullPair(int n, const vector<int>& a, const vector<int>& b) {
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        vector<int> b(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        
        string result = isDullPair(n, a, b);
        
        cout << result << endl;
    }
    
    return 0;
}
