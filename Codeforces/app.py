#include <iostream>
#include <cmath>

using namespace std;

int binary_search(int a, int b, int c) {
    int low = 0;
    int high = pow(2, 30);
    while (low < high) {
        int mid = (low + high) / 2;
        if ((a ^ mid) - (b ^ mid) < 0 && (c ^ mid) - (b ^ mid) > 0) {
            return mid;
        }
        else if ((a ^ mid) - (b ^ mid) >= 0) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    return -1;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int x = binary_search(a, b, c);

    if (x == -1) {
        cout << "-1" << endl;
    }
    else {
        cout << x << endl;
    }

    return 0;
}
