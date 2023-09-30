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

char get(int i)
{
    return 'a' + i - 1;
}

const int INF = 1e9 + 7;

int myans(int n)
{
    int pow = 1;
    while (pow <= n)
    {
        pow *= 2;
    }
    return pow;
}

int bpow(int base, int exp)
{
    int res = 1;
    while (exp)
    {
        if (exp % 2 == 1)
        {
            res = (res * base) % mod;
        }
        exp >>= 1;
        base = (base * base) % mod;
    }
    return res;
}

int badd(int a, int b)
{
    return (a + b) % mod;
}
int bsub(int a, int b)
{
    return (((a - b) % mod) + mod) % mod;
}
int bmul(int a, int b)
{
    return ((a % mod) * (b % mod)) % mod;
}

int binv(int base)
{
    return bpow(base, mod - 2);
}

int bdiv(int a, int b)
{
    return bmul(a, binv(b));
}

int pow2(int n){
    int ans = 1;
    for(int i=0;i<n;i++){
        ans*=2;
    }
    return ans;
}

bool issorted(vector<int> a){
    for(int i=0;i<a.size()-1;i++){
        if(a[i]>a[i+1]){
            return false;
        }
    }
    return true;
}




void solve(){
    int n;
    cin>>n;

    vector<int> a(2*n);

    for(int i=0;i<2*n;i++){
        cin>>a[i];
    }

    vector<int> b(2*n);
    b=a;

    int ans1 = INT_MAX,ans2=INT_MAX;
    int t=0;
    for(int i=0;i<2*n;i++){
        if(issorted(b)){
            ans1 = min(ans1,i);
            break;
        }
        if(t==0){
            for(int j=0;j<2*n;j+=2){
                swap(b[j],b[j+1]);
            }
            t=1;
        }
        else{
            for(int j=0;j<n;j++){
                swap(b[j],b[j+n]);
            }
            t=0;
        }

    }
    b=a;
    t=1;

    for(int i=0;i<2*n;i++){
        if(issorted(b)){
            ans2 = min(ans2,i);
            break;
        }
        if(t==0){
            for(int j=0;j<2*n;j+=2){
                swap(b[j],b[j+1]);
            }
            t=1;
        }
        else{
            for(int j=0;j<n;j++){
                swap(b[j],b[j+n]);
            }
            t=0;
        }

    }

    if(ans1==INT_MAX && ans2==INT_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<min(ans1,ans2)<<endl;
    }


}




int32_t main(){

    fastIO;
    auto start = std::chrono::high_resolution_clock::now();
    int t=1;
    while(t--) solve();

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    #ifndef ONLINE_JUDGE
        cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s"<< endl;
    #endif
    return 0;
}

