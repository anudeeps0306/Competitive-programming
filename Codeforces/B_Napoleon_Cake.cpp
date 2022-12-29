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
    vector<int> a(n);

    for(auto &it : a){
        cin>>it;
    }

    vector<int> dp(n+1,0);
    // dp[n-1]=a[n-1];
    for(int i=n-1;i>=0;i--){
        dp[i] = max(dp[i+1]-1,a[i]);
    }

    for(int i=0 ; i<n ;i++){
        if(dp[i]>0) cout<<1<<" ";
        else cout<<0<<" ";
    }
    // while(i>=0){
    //     if(a[i]==0){
    //         ans[i]=0;
    //         i--;
    //     }
    //     else{
    //         int new1 = a[i];
    //         int j = i - new1;
    //         while(i>=0 && j!=i){
    //             ans[i]=1;
    //             i--;
    //         }
    //         i=i-new1;
    //     }
    // }

    // for(auto it : ans) cout<<it<<" ";
    cout<<endl;
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