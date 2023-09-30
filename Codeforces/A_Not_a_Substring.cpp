#include<bits/stdc++.h>
#define mod 1000000007
#define PI 3.1415926535897932384626
#define endl "\n"
using namespace std;


string generateRegularSequence(int n) {
    string regularSeq(n, '(');
    regularSeq += string(n, ')');
    return regularSeq;
}

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

void solve(){
    string seq;
        cin >> seq;

        int n = seq.size();

        string compare = "()",regSeq = generateRegularSequence(seq.length());

        if (seq == compare) {
            cout << "NO" << endl;
            return;
        }

        string ans2="";

        for(int i=0; i<2*n ;i++){
            if(i%2==0){
                ans2+="(";
            }
            else{
                ans2+=")";
            }
        }
        cout<<"YES"<<endl;
        if (regSeq.find(seq) != string::npos) {
            string repSeq = "";
            for (int i=0; i<seq.size();i++) {
                repSeq += compare;
            }
            cout << repSeq << endl;
            return;
        } 
         else {
            cout << regSeq << endl;
            return;
        }

        cout<<ans2<<endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();

    }

    return 0;
}
