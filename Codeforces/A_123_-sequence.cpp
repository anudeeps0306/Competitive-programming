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

bool equals(int a[], int b[], int n){
    int dif = INT_MAX;
    for(int i = 0; i < n; i++){
        if(b[i] != 0) dif = min(dif, a[i] - b[i]);
    }
    if(dif < 0) return false; 
    if(dif == INT_MAX) return true;
    for(int i = 0; i < n; i++){
        if(a[i] - b[i] > dif) return false;
        if(b[i] != 0 && a[i] - b[i] < dif) return false;
    }
    return true;
}


void solve(){
    int n,input;
    cin>>n;
    int a=0,b=0,c=0;

    for(int i=0;i<n;i++){
        cin>>input;
        if(input==1) a++;
        else if(input==2) b++;
        else c++;
    }
    
    int max = a;
    if(b>max) max=b;
    if(c>max) max=c;

    if(max==a){
        cout<<n-a<<endl;
    }
    else if(max==b){
        cout<<n-b<<endl;
    }
    else{
        cout<<n-c<<endl;
    }

}
 
int32_t main(){
 
    fastIO;
    auto start = std::chrono::high_resolution_clock::now();

    // int t;
    // cin>>t;
    // while(t--)
    solve();
 
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // #ifndef ONLINE_JUDGE
    //     cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s"<< endl;
    // #endif
    return 0;
}