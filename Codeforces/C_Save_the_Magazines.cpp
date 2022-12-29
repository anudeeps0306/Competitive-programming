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
    string s;
    cin>>s;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int sum=0;   
    int maxi,mini;
     for(int i=0;i<3;i++){
        maxi=max(maxi,a[i]);
        mini=min(mini,a[i]);  
    }
    int dif = maxi-mini;
    bool flag = false;
    for(int i=0;i<3;i++){
        if(a[i]==dif){
            flag=true;
        }
    }
    // for(int k=0;k<n;k++){
    //     if(s[k]=='0' && k<=n-1){
    //             if(s[j]<s[k]){
    //                 break;
    //             }
    //             else{
    //             }
    //             k++;
    //         }
    //         k=k-1;
    //     }
    // }
    for(int i=0;i<n;i++){
        if(s[i]=='0' && i<=n-1){
            int end=i+1;while(s[end]=='1' && end<=n-1){if(a[end]<a[i]){sum+=a[i];s[end]='0';s[i]='1'; break;
                }
                else sum+=a[end];end++;}i=end-1;
        }
        else if(s[i]=='1')sum+=a[i];
        
    }
    cout<<sum<<endl;
    // if(s[0]==1){
    //     sum+=s[0];
    // }
    // for(int i=1;i<n;i++){
    //     if(s[i]=='1'){
    //         if(s[i-1]=='1'){
    //         }
    //         else{
    //             if(a[i-1]>a[i]){
    //                 s[i]='0';
    //                 s[i-1]='1';
    //             }
    //         }
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     if(s[i]=='1'){
    //         sum+=a[i];
    //     }
    // }
    // int prev=0
    // for(int i=0;i<n;i++){
    //     if(s[i]!=1){
    //         prev=
    //     }
    // }
    // cout<<s;
    // cout<<sum<<endl;

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