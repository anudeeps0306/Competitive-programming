#include <bits/stdc++.h>
using namespace std;

const int mod = 123;

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

void solve(int pos)
{
  int n;
  cin >> n;
  vector<int> this_is(n);
  for (int i = 0; i < n; i++)
  {
    cin >> this_is[i];
  }

  sort(this_is.begin(), this_is.end());
  float ans = 0,ap,bp,a1,b1;

  if (n == 5)
  {
    ap = (this_is[0] + this_is[2]) / 2.0;
    bp = (this_is[3] + this_is[4]) / 2.0;
    a1 = (this_is[0] + this_is[1]) / 2.0;
    b1 = (this_is[2] + this_is[4]) / 2.0;

    ans = max((abs(ap - bp)), abs(a1 - b1));
  }
  else
  {
    ap = (this_is[0] + this_is[1]) / 2.0;
    bp = (this_is[n - 1] + this_is[n - 2]) / 2.0;
    ans = abs(ap - bp);
  }

  cout << "Case #" << pos << ": " << fixed << setprecision(6) << ans << endl;
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  int pos = 1;

  while (t--)
  {
    solve(pos);
    pos++;
  }
  return 0;
}