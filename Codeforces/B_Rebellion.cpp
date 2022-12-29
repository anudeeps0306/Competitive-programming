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
    int n,res=0,right=0;
    bool flag=false;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    // for(int i=0;i<v1.size();i++){
    //     if(i<v2.size())
    //     ans+=min(v1[i],v2[i]);
    //     else ans+=v1[i];
    // }
    // cout<<ans<<endl;
    int left=n-1;
    while(right<left){while(a[left]!=0&&left>=0&&right<left)left--;if(a[left]!=0){flag=true; cout<<res<<endl;break;} 
    while(right<left&&right<n&&a[right]!=1)right++;
    // int count_o=0,index=0,ncount=0;
    // for(int i=0;i<n;i++){
    //     if(a[i]==1){
    //         index=i;
    //         break;
    //     }
    // }
    // int count1=0;
    // vector<int> v1,v2;
    // for(int i=index;i<n;i++){
    //     if(a[i]==0){
    //         if(count1>0) v2.push_back(count1);
    //         count1=0;
    //         count_o++;
    //     }
    //     else{
    //         if(count_o > 0) v1.push_back(count_o);
    //         count_o=0;
    //         count1++;
    //     }
    // }
    if(a[right]!=1){flag=true;cout<<res<<endl;break;}
    // if(count_o > 0) v1.push_back(count_o);
    // for(auto it : v1) cout<<it<<" ";
    // cout<<endl;
    // for(auto it : v2) cout<<it<<" ";

    // for()
    // if(count_o == 0) cout<<0;
    // else if(count_o>n-index) cout<<n-index;
    // else cout<<count_o;
    // int ans=0;
    a[left--]=1;res++;right++;}if(!flag)cout<<res<<endl;


    
    
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