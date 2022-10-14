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
 
void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int g1=a[0];
    int g2=a[1];
    for(int i=0;i<n;i++){
        if(i%2==0){
            g1 = __gcd(g1,a[i]);
        }
        else{
            g2 = __gcd(g2,a[i]);
        }
    }
    cout<<g1<<" "<<g2<<endl;
    bool flag1=true,flag2=true;
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(a[i]%g2!=0) flag1=false;
        }
        else{
            if(a[i]%g1!=0) flag2=false;
        }
    }
    cout<<flag1<<" "<<flag2<<endl;
    if(flag1) cout<<g1;
    else if(flag2) cout<<g2;
    else cout<<0;
    cout<<endl;
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