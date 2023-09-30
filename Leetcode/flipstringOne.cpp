#include <iostream>
using namespace std;


int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}


int calculateVisits(int N) {
    return factorial(N);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int ways = calculateVisits(N);
        cout << ways << endl;
    }

    return 0;
}
