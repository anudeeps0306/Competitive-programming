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


int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool comparePairs(const pair<int, int> &a, const pair<int, int> &b) {
    return a > b;
}

void sortAndReversePairs(vector<pair<int, int>> &pairs) {
    sort(pairs.begin(), pairs.end(), comparePairs);
}

int help(const vector<int>& b) {
    int n = b.size();
    int sum_terms = 0;
    int max_term = numeric_limits<int>::min();
    
    for (int i = 0; i < n; ++i) {
        sum_terms += b[i] * (i + 1);
        max_term = max(max_term, b[i] * (i + 1));
    }
    
    return sum_terms - max_term;
}

pair<int,int> find2(int a,int k){
    int cnt=0;
    while(a%2==0 && a!=k){
        a/=2;
        cnt++;
    }
    return {a,cnt};
}

int brute(int n,int m){
    int cnt=0;
    
    while(n > m){
        m*=2;
        cnt++;
    }

    return cnt+(m-n);
}

int find(int n,int m){

    pair<int,int> p = find2(m,n);

    if(p.first > n){
        return brute(p.first, n);
    }
    else if(p.first < n){
        return n-p.first+p.second;
    }
   
    return p.second;

}

int count(int n, int m, int d) {
    int cnt = 0;
    while (n <= m) {
        n *= d;
        cnt++;
    }
    return cnt;
}

void totalpossible(int n, int m) {
    unordered_map<int, int> freqMap;
    for (int i = 2; i <= m/n; i++) {
        freqMap[i]=count(n, m, i);
    }

    for(auto it : freqMap){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

void solve() {
    int i,l,r,cnt,lim;
    cin>>l>>r;
		for(cnt=1;(l<<cnt)<=r;cnt++);
		cout<<cnt<<' ';
		if(cnt==1)
		{
			cout<<r-l+1<<endl;
			return;
		}
		if((l<<(cnt-2))*3<=r)
		{
			lim=((r/3)>>(cnt-2));
			cout<<((lim-l+1)*cnt+(r>>(cnt-1))-lim)%998244353<<endl;
		}
		else cout<<(r>>(cnt-1))-l+1<<endl;


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
