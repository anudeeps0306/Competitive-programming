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

int getit(int l,int r){
    if(l-r==1) return 0;
    int mid = (l+r)<<1;

    int max1 = *max_element(a,a+l);
    int max2 = *max_element(a+l,a+n);

    if(max1 > max2){
        swap(a[])
    }
}
 
void solve(){
    int n;
    cin>>n;
    int v[n];
    for(int i=0;i<n;i++) cin>>v[i];
    int max=*max_element(v.begin(), v.end()); 
    int min=*min_element(v.begin(), v.end()); 
    // for(int i=0;i<n;i/=2){

    int ans = getit(0,n);
}
 
int32_t main(){
 
    fastIO;
    auto start = std::chrono::high_resolution_clock::now();
 
    int t;
    cin>>t;
    while(t--) solve();
 
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    #ifndef ONLINE_JUDGE
        cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s"<< endl;
    #endif
    return 0;
}