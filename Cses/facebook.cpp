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

using namespace std;

const int MAXI_ = 1572864;
int dp[MAXI_ + 1][42];


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



bool solve(int p, vector<int> &ans, int sum)
{
  if (p == 1 && sum == 0)
  {
    return true;
  }
  if (dp[p][sum] != -1)
  {
    return dp[p][sum];
  }
  for (int i = 41; i >= 1; i--) 
  {
    if (p % i == 0 && sum >= i)
    {
      sum -= i;
      p /= i;
      ans.pb(i);
      if (solve(p, ans, sum))
      {
        dp[p][sum] = true;
        return true;
      }
      ans.pop_back();
      p *= i;
      sum += i;
    }
  }
  dp[p][sum] = false;
  return false;
}


void solve(int pos)
{
  int p;
  cin >> p;

  memset(dp,-1,sizeof(dp));

  if (p > MAXI_)
  {
    cout << "Case #" << pos << ": -1" << endl;
    return;
  }

  if(p < 41){
    cout << "Case #" << pos << ": " << 41-p+1 <<" ";
    for(int i=0 ;i<41-p ;i++){
        cout<<1<<" ";
    }
    cout<<p;
    cout<<endl;
    return;
  }

  vector<int> ans;

  if (solve(p, ans, 41))
  {
    cout << "Case #" << pos << ": ";
    cout << ans.size() << " ";

    for (auto it : ans)
    {
      cout << it << " ";
    }

    cout << endl;
  }

  else
  {
    cout << "Case #" << pos << ": -1" << endl;
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  int i = 1;
  while (t--)
  {
    solve(i);
    i++;
  }
  return 0;
}