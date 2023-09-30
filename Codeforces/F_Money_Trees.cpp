#include <bits/stdc++.h>
using namespace std;
#define fastIO                             \
    {                                      \
        ios_base ::sync_with_stdio(false); \
        cin.tie(NULL);                     \
        cout.tie(NULL);                    \
    }
#define mod 1000000007
#define PI 3.1415926535897932384626
#define endl "\n"
#define YES cout << "YES" \
                 << "\n"
#define NO cout << "NO" \
                << "\n"
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

bool clean(string str)
{
    bool flag = false;
    int n;

    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == 'A' && str[i + 1] == 'B')
        {
            flag = true;
        }
        else if (str[i] == 'B' && str[i + 1] == 'B')
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

    for (int index = 2; index < i; index++)
    {
        if (i % index != 0)
        {
            return index;
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

// function to find factorial of a n number
int fact(int n)
{
    int sum = 1;
    for (int i = 2; i <= n; i++)
    {
        sum *= i;
    }
    return sum;
}
int maxi = INT_MIN;

int bfs(vector<int> adj[], int s, vector<bool> &visited, int n) {
    if (adj[s].size() == 0) {
        return 0;
    }

    visited[s] = true;

    int maxi = 0; 

    priority_queue<int> q;
    for (auto it : adj[s]) {
        if (!visited[it]) {
            q.push(bfs(adj, it, visited, n));
        }
    }
    int time = 1;
    while (!q.empty()) {
        int it = q.top();
        q.pop();
        maxi = max(it + time, maxi);
        time++;
    }
    // int size = adj[s].size();
    // maxi = max(maxi, size);

    return maxi;
}

int f(pair<int,int> p,vector<int> &a,int k){
    
    int start = p.first;
    int end = start;
    int dif = end-start;
    int ans = 0,sum = 0;
    int n = p.second;

    while(end<=n){
        dif = end-start;
        if(sum>k){
           sum-=a[start];
           start++;
        }
        else{
            ans = max(ans,abs(dif));
            sum+=a[end];
            end++;
        }
    }
    dif = end-start;
    if(sum>k){
        return ans;
    }
    return max(ans,abs(end-start));
    
    
}

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

void solve() {
    int n,k;
    cin>>n>>k;

    vector<int> a(n),b(n);
    vector<pair<int,int>> points;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<n;j++){
        cin>>b[j];
    }

    int pos = 0;

    for(int i=0;i<n-1;i++){
        if(b[i]%b[i+1]!=0){
            points.push_back({pos,i});
            pos = i+1;
        }
    }

    points.push_back({pos,n-1});

    int sum=0;

    for(int i=0 ; i<points.size() ; i++){
        if(sum < f(points[i],a,k)){
            sum = f(points[i],a,k);
        }
    }

    cout<<sum<<endl;

}


int32_t main()
{

    fastIO;
    auto start = std::chrono::high_resolution_clock::now();

    int t;
    cin>>t;
    while (t--)
        solve();

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // #ifndef ONLINE_JUDGE
    //     cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"str"<< endl;
    // #endif
    return 0;
}

