#include <iostream>
#include <vector>
#include <map>

using namespace std;

void printVector(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ' ';
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> arrayA(n), arrayB(n);
    map<int, vector<int>> occurrences;

    for (int i = 0; i < n; i++) {
        cin >> arrayA[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> arrayB[i];
    }

    for (int i = 0; i < n; i++) {
        arrayA[i] -= arrayB[i];
        occurrences[arrayA[i]].push_back(i);
    }

    vector<int> indices;

    int uniqueValue = 0;

    for (auto entry : occurrences) {
        uniqueValue = entry.first;
        indices = entry.second;
    }

    for (int i = 0; i < indices.size(); i++) {
        indices[i] += 1;
    }

    cout << indices.size() << endl;
    printVector(indices);
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
