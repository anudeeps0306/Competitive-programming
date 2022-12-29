#include <bits/stdc++.h>
using namespace std;
#define fastIO          {ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define mod             1000000007
#define PI              3.1415926535897932384626
#define endl            "\n"
#define YES             cout << "YES" << "\n"
#define NO              cout << "NO" << "\n"
#define ispowoftwo(n)   (!(n & (n-1)))
#define pb              push_back
#define ppb             pop_back
#define int              long long
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef vector<vi> vvi;
 
 
 
int lcm(int a, int b){
    return (a / __gcd(a, b)) * b;
}

bool clean(string s){
    bool flag = false;

    for(int i=0;i<s.length()-1;i++){
        if(s[i]=='A' && s[i+1]=='B'){
            flag=true;
        }
        else if(s[i]=='B' && s[i+1]=='B'){
            flag=true;
        }
    }
    return flag;
}



 
void solve(){
    int n,h;
    cin>>n>>h;

    vector<int> v(n);

    for (int &it : v) cin >> it;
    int l = 1, r = 1e18;
    while (l <= r) {
      int m = (l + r) / 2;
      int sum = m;
      for (int i = 0; i < n - 1; ++i) 
        sum += min(m, v[i + 1] - v[i]);
      if (sum < h) l = m + 1;
      else r = m - 1;
    }
    cout << r + 1 << '\n';

}

 
int32_t main(){
 
    fastIO;
    auto start = std::chrono::high_resolution_clock::now();
 
    int t;
    cin>>t;
    while(t--) 
    solve();
 
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // #ifndef ONLINE_JUDGE
    //     cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s"<< endl;
    // #endif
    return 0;
}