
#include <bits/stdc++.h>
using namespace std;
#define fastIO          {ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define int             long long
#define mod             1000000007
#define PI              3.1415926535897932384626
#define endl            "\n"
#define YES             cout << "YES" << "\n"
#define NO              cout << "NO" << "\n"
#define ispowoftwo(n)   (!(n & (n-1)))
#define pb              push_back
#define ppb             pop_back
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef vector<vi> vvi;
 
 
 
int lcm(int a, int b){
    return (a / __gcd(a, b)) * b;
}

bool equals(int a[], int b[], int n){
    int dif = INT_MAX;
    for(int i = 0; i < n; i++){
        if(b[i] != 0) dif = min(dif, a[i] - b[i]);
    }
    if(dif < 0) return false; 
    if(dif == INT_MAX) return true;
    for(int i = 0; i < n; i++){
        if(a[i] - b[i] > dif) return false;
        if(b[i] != 0 && a[i] - b[i] < dif) return false;
    }
    return true;
}
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

bool check(char c){
   if(c>='a' && c<='z') return true;
    return false;
}

string check(string a,string b,string c){
    if(a == "paper" && b == "rock" && c == "rock") return "F";
    if(a == "scissors" && b == "paper" && c == "paper") return "F";
    if(a == "rock" && b == "scissors" && c == "scissors") return "F";

    if(a == "rock" && b == "paper" && c == "rock") return "M";
    if(a == "paper" && b == "scissors" && c == "paper") return "M";
    if(a == "scissors" && b == "rock" && c == "scissors") return "M";

    if(a == "rock" && b == "rock" && c == "paper") return "S";
    if(a == "paper" && b == "paper" && c == "scissors") return "S";
    if(a == "scissors" && b == "scissors" && c == "rock") return "S";
    // if(a == "paper" && b == "scissors" && c == "rock") return "M";
    // if(a == "scissors" && b == "paper" && c == "rock") return "F";
    // if(a == "scissors" && b == "rock" && c == "paper") return "M";
    return "?";
}

void solve(){
    string s1,s2,s3;
    cin>>s1>>s2>>s3;

    cout<<check(s1,s2,s3);

}
 
int32_t main(){
 
    fastIO;
    auto start = std::chrono::high_resolution_clock::now();

    // int t;
    // cin>>t;
    // while(t--)
    solve();
 
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // #ifndef ONLINE_JUDGE
    //     cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s"<< endl;
    // #endif
    return 0;
}