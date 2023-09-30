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


int check( int i , vector<int> ans){
    for(auto it : ans){
        if(it%i != 0){
            return -1;
        }
    }

    if(i==1) return 2;

    for(int j=2;j<i;j++){
        if(i%j != 0){
            return j;
        }
    }

    return i+1;
}



 
vector<int> solve() {
    int N;
    char C;
    string S;
    cin >> N >> C >> S;
    if (S == string(N, C)) return {};
    for (int i = 0; i < N; i++) {
        bool good = true;
        for (int j = i; j < N; j += (i + 1)) if (S[j] != C) good = false;
        if (good) return {i + 1};
    }
    return {N - 1, N};
}
 
int32_t main() {
    int T;
    cin >> T;
    while (T--) {
        auto ret = solve();
        cout << ret.size() << '\n';
        for (auto x : ret) cout << x << ' ';
        cout << '\n';
    }
}
