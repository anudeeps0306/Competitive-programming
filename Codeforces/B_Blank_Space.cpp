#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
        
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
        
    int max_length = 0;
    int current_length = 0;
        
    for (int i = 0; i < n; i++) {
        if (heights[i] == 0) {
            current_length++;
            max_length = max(max_length, current_length);
        } else {
            current_length = 0;
        }
    }
        
    cout << max_length << endl;
}

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
