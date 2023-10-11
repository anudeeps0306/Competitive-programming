#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define len length
#define ull unsigned long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define yes cout<<"Yes\n"; 
#define no cout<<"No<<\n"; 
#define minpq priority_queue<ll,vector<ll>,greater<ll>>
#define speed ios :: sync_with_stdio(0); cin.tie(0); cout.tie(nullptr);
ll m = 1e9 + 7;

ll hsh[2000006];
ll hsh1[2000006];

bool isPrime(ll n)
{
 if (n <= 1)
        return false;

   for (int i = 2; i * i <= n; i++)
  {
       if (n % i == 0)
            return false;
  }
 return true;
}

ll find_nsum(ll n){
   ll k= sqrt(2*n);
    k+=1;
    if((k*(k-1))/2<=n) 
    return k;
    else{
        return k-1;
    }
}


ll _max(long long int a, long long int b)
{
 if (a > b)
    return a;
else
   return b;
}
ll _min(long long int a, long long int b)
{
 if (a < b)
    return a;
else
   return b;
}
int main()
{

 ll  t, n, k, a, in,b, c, l1,r1,x, y, w, h, l,r,z, ct, x1, sum, sum2, max, min;

   ll  k2, q;
    ll ct2;

    string s;
    cin >> t;
    char ch;
int i=0;
    while (t--)
   {
    i++;
       vector<pair<ll,ll>> vp, vp1;
map<ll,ll> mp,mp1;
       cin>>n;
       min= INT_MAX;
       vector<long double> v(n), v1;
       max=-1;
        sort(all(v));
        for(int i=0; i<n; i++) cin>>v[i];
        long double ans11= (v[n-1]+v[n-2])/2- (v[2]+v[0])/2;
        long double ans12= (v[n-1]+v[n-3])/2 - (v[1]+ v[0])/2;
        long double ans13= (v[n-1]+v[n-2])/2 - (v[1]+ v[0])/2;
        
        ld answer= ans13;
        if(n==5){
            answer= (_max(ans11,ans12));
        }
            cout<<"Case #"<<i<<": "<<answer<<endl;
     
      
   }


   return 0;
}