
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod             1000000007

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

int pow(int n,int k){
    int ans=1;
    for(int i=0;i<k;i++){
        ans = bmul(ans,n);
    }
    return ans;
}



int32_t main()
{
    int t;
    cin >> t;
 
    while (t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<0<<endl;
        }
        else{
            int ans = sqrt(n-1);
            cout<<ans<<"\n";
        }
    }
        
    return 0;
}