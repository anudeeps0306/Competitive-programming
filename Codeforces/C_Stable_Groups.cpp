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

string v[200];

void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a,a+n);

    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;

    vector<int> ans;

    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]>k){
            ans.push_back((a[i]-a[i-1]-1)/k);
        }
    }

    sort(ans.begin(),ans.end());
    // int test;
    // for(int i=0;i<ans.size();i++){
    //     test = ans[i];
    //     if(test/k <= m && test%k == 1){
    //         m -= test/k;
    //         ans[i] = 0;
    //     }
    //     else if(test/k-1 <= m && test%k == 0){
    //         m -= test/k-1;
    //         ans[i] = 0;
    //     }
    //     else{
    //         break;
    //     }
    // }
    // cout<<endl;
    // for(auto it : ans){
    //     cout<<it<<" ";
    // }

    int ans1 = 1;

    for(int i=0;i<ans.size();i++){
        if(ans[i] <= m){
            m-=ans[i];
            ans[i]=0;
        }
        else{
            break;
        }
    }

    for(auto it : ans){
        
        if(it!=0){
            ans1++;
        }
    }

    
    cout<<ans1<<endl;
    
}

 
int32_t main(){
 
    fastIO;
    auto start = std::chrono::high_resolution_clock::now();
 
    int t=1;
    while(t--) 
    solve();
 
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // #ifndef ONLINE_JUDGE
    //     cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s"<< endl;
    // #endif
    return 0;
}

