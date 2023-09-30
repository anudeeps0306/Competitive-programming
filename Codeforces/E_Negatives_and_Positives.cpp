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
#define mod             1000000007
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef vector<vi> vvi;
 
 
 
int lcm(int a, int b){
    return (a / __gcd(a, b)) * b;
}

bool clean(string str){
    bool flag = false;
    int n;

    for(int i=0;i<n-1;i++){
        if(str[i]=='A' && str[i+1]=='B'){
            flag=true;
        }
        else if(str[i]=='B' && str[i+1]=='B'){
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

    for(int index=2;index<i;index++){
        if(i%index != 0){
            return index;
        }
    }

    return i+1;
}

char get(int i) {
    return 'a' + i - 1;
}

const int INF = 1e9 + 7; 

int myans(int n){
    int pow =1;
    while(pow<=n){
        pow*=2;
    }
    return pow;
}

int bpow(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        exp >>= 1;
        base = (base * base) % mod;
    }
    return res;
}

int badd(int a, int b) {
    return (a + b) % mod;
}
int bsub(int a, int b) {
    return (((a - b) % mod) + mod) % mod;
}
int bmul(int a, int b) {
    return ((a % mod) * (b % mod)) % mod;
}

int binv(int base) {
    return bpow(base, mod - 2);
}

int bdiv(int a, int b) {
    return bmul(a, binv(b));
}

//function to find factorial of a n number
int fact(int n){
    int sum=1;
    for(int i=2;i<=n;i++){
        sum*=i;
    }
    return sum;
}

int mfact(int n){
    int sum=1;
    for(int i=2;i<=n;i++){
        sum*=i;
        sum%=mod;
    }
    return sum;
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int neg=0,sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]<0){
            arr[i]=(-arr[i]);
            neg++;
        }
        sum+=arr[i];
    }

    if(neg%2==1){
        sort(arr,arr+n);
        sum-=2*arr[0];
        cout<<sum<<endl;
        return;
    }
    cout<<sum<<endl;
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
    //     cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"str"<< endl;
    // #endif
    return 0;
}




