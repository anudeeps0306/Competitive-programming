#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        if (a > b)
            swap(a, b);

        int ans = ceil((b-a)/2.0) + ceil(sqrt(a));

        cout << ans << endl;
    }

    return 0;
}
