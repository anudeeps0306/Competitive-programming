#include <bits/stdc++.h>
using namespace std;
#define fastIO                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
#define mod 1000000007
#define PI 3.1415926535897932384626
#define endl "\n"
#define YES cout << "YES" << "\n"
#define NO cout << "NO" << "\n"
#define ispowoftwo(n) (!(n & (n - 1)))
#define pb push_back
#define ppb pop_back
#define int long long

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef vector<vi> vvi;

int lcm(int a, int b)
{
    return (a / __gcd(a, b)) * b;
}

bool clean(string s)
{
    bool flag = false;

    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == 'A' && s[i + 1] == 'B')
        {
            flag = true;
        }
        else if (s[i] == 'B' && s[i + 1] == 'B')
        {
            flag = true;
        }
    }
    return flag;
}

int check(int i, vector<int> ans)
{
    for (auto it : ans)
    {
        if (it % i != 0)
        {
            return -1;
        }
    }

    if (i == 1)
        return 2;

    for (int j = 2; j < i; j++)
    {
        if (i % j != 0)
        {
            return j;
        }
    }

    return i + 1;
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

int pow2(int n)
{
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= 2;
    }
    return ans;
}

void dfs(vector<vector<pair<int,int>>>& v,vector<int>& visited, int pos,vector<int>& ans){
    visited[pos]=1;


    for(auto it : v[pos]){
        if(!visited[it.first]){
            ans[it.first] = ans[pos] + it.second;
            dfs(v,visited,it.first,ans);
        }
    }
}



void solve()
{   
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> v(n+1);

    vector<vector<int>> query(m,vector<int>(3));

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].pb({b,c});
        v[b].pb({a,c});
        query[i] = {a,b,c};

    }

    vector<int> visited(n+1,0);
    vector<int> ans(n+1,0);

    for(int i=1;i<=n ;i++){
        if(!visited[i]){
            dfs(v,visited,i,ans);
        }
    }

    for(int i=0;i<m;i++){
        int a = query[i][0];
        int b = query[i][1];
        int c = query[i][2];

        if(ans[b] - ans[a] != c){
            cout<<"NO"<<endl;
            return;
        }
    }

    for(int i=0;i<n;i++){
        cout<<ans[i+1]<<" ";
    }
    cout<<endl;

    cout<<"YES"<<endl;

    
    


}

int32_t main()
{
    fastIO;
    auto start = chrono::high_resolution_clock::now();
    int t;
    cin >> t;
    while (t--)
        solve();

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    // #ifndef ONLINE_JUDGE
    //     cerr << "Time taken : " << ((long double)duration.count()) / ((long double)1e9) << "s" << endl;
    // #endif
    return 0;
}
