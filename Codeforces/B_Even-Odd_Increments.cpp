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
    int n,q,ans=0;
    cin>>n>>q;
    int sum_even =0 ,sum_odd = 0;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans+=a[i];
        if(a[i]%2==0){
            sum_even++;
        }
        else{
            sum_odd++;
        }
    }
    while(q--){
        int ind,add;
        cin>>ind>>add;
        if(ind == 1){
            ans += sum_odd*add;
            if(add%2==1){
               sum_even += sum_odd;
               sum_odd = 0; 
            }
        }
        else if(ind == 0){
            ans+= sum_even*add;
            if(add%2==1){
                sum_odd += sum_even;
                sum_even=0;
            }
        }
        cout<<ans<<endl;
    }

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