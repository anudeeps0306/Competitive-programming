
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

bool comp(pair<int, string> a, pair<int,string> b){
    if(a.first==b.first){
        return true;
    }
    else if(a.first>b.first){
        return true;
    }
    return false;
}
    

void solve(){
   vector<pair<int, string>> v;
   int t,k=t;
   cin>>t;
   while (k--){
        int x;
         string s1,s2;
         cin>>s1>>s2;
         if(s2== "rat") x=1;
         else if(s2=="child") x=2;
         else if(s2=="woman") x=2;
         else if(s2 == "man") x=3;
         else x=4;
         v.push_back({x,s1});
   }

   sort(v.begin(),v.end(),comp);
   
   for(auto it : v) cout<<it.first;


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