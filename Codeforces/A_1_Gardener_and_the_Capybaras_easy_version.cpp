#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int len = s.length();
        int n=len;
        int idx = -1;
        for (int i = 0; i < len; i++) {
            if (s[i] == 'b') {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            cout << ":(" << endl;
        }
        else if(idx==len-1){
            cout<<s.substr(0,1)<<" "<<s.substr(1,n-2)<<" "<<s.substr(n-1,1)<<endl;
        }
        else {
            cout << s.substr(0, idx) << " " << s[idx] << " " << s.substr(idx + 1, len - idx - 1) << endl;
        }
    }
    return 0;
}
