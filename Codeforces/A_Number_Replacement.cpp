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
    string s;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>s;
    
    map<int,char> m;

    bool flag=true;
    for(int i=0;i<n;i++){
        if(m[a[i]]!=s[i]){
            if(m[a[i]]=='\0'){
                m[a[i]]=s[i];
            }
            else{
                flag=false;
            }
        }
    }
    if(flag) cout<<"YES";
    else cout<<"NO";
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