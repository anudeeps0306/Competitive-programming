#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> efficiency(n - 1);
        int sum = 0;

        for (int i = 0; i < n - 1; i++) {
            cin >> efficiency[i];
            sum += efficiency[i];
        }

        
        int missing_efficiency = -sum;
        cout << missing_efficiency << endl;
    }
    return 0;
}
