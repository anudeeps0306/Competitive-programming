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
 
void solve(){
    string s;
    bool flag=true;
    cin>>s;
    int count=0,ans=INT_MIN;
    for(int i=s.length()-1;i>=0;i--){
    int start=i;
    flag=true;
    while(start>0 && flag){
        if(s[start]=='5'){
            start--;
            while(start>=0){
                if(s[start]=='2' || s[start]=='7'){
                    ans=max(ans,start);
                    flag=false;
                    break;
                }
                else{
                    start--;
                }
            }
        }
        else if(s[start]=='0'){
            start--;
            while(start>=0){
                if(s[start]=='0' || s[start]=='5' ){
                    ans=max(ans,start);
                    flag=false;
                    break;
                }
                else{
                    start--;
                }
            }
        }
        start--;
    }
    }

    // cout<<ans<<endl;
     cout<<s.length()-ans-2<<endl;
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