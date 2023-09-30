#include <bits/stdc++.h>
using namespace std;
#define fastIO          {ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define mod             1000000007
#define PI              3.1415926535897932384626
#define endl            "\n"
#define int              long long
 



int calc(int x, int y, vector<int> c, vector<int> a, vector<int> b) {
    return (a[y] * x * x) + (b[y] * x) + c[y];
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> k(n + 1), a(m + 1), b(m + 1), c(m + 1);

    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    for (int i = 1; i <= m; i++) {
        bool found = false;
        for (int j = 1; j <= n; j++) {
            if (a[i] * k[j] * k[j] + b[i] * k[j] > 0) {
                if (calc(k[j], i, c, a, b) < 0) {
                    cout << "YES" << endl << -k[j] << endl;
                } else {
                    cout << "YES" << endl << k[j] << endl;
                }
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "NO" << endl;
        }
    }

    return;
}

 
int32_t main(){
 
    fastIO;
    auto start = std::chrono::high_resolution_clock::now();
 
    int t;
    cin>>t;
    while(t--) solve();
 
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // #ifndef ONLINE_JUDGE
    //     cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s"<< endl;
    // #endif
    return 0;
}

