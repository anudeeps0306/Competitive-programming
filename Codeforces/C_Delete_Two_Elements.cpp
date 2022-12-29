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



 
void solve(){
    int n,sum=0;
    cin>>n;
    vector<int> v(n);
    map<int,int> m;

    for(int i=0;i<n;i++){
        cin>>v[i];
        sum += v[i];
        m[v[i]]++;
    }

    int find = sum-(sum/n)*(n-2);

    // cout<<find;

    int ans=0;

    if((2*sum)%n != 0 ){
        cout<<0;
    }
    else{
        int need = (2*sum)/n;
        for(int i=0;i<n;i++){
            if(m[need - v[i]]!=0){
                ans+=m[need-v[i]];
            }
            if(need-v[i] == v[i]){
                ans-=1;
            }


        }
        cout<<ans/2;
    }
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

