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
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    if(s1[n-1]==s2[m-1]){
        if(s1[n-1]=='S'){
        if(n==m){
            cout<<"=";
        
        }
        else if(n>m)cout<<"<";
        else cout<<">";
        }
        else{
            if(n==m){
                cout<<"=";
            }
            else if(n>m) cout<<">";
            else cout<<"<";
        }
    }
    else if(s1[n-1]=='M'&&s2[m-1]=='L'){
        cout<<"<";
    }
    else if(s1[n-1]=='S'&&s2[m-1]=='L'){
        cout<<"<";
    }
    else if(s1[n-1]=='S'&&s2[m-1]=='M'){
        cout<<"<";
    }
    else cout<<">";
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
    // #ifndef ONLINE_JUDGE
    //     cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s"<< endl;
    // #endif
    return 0;
}