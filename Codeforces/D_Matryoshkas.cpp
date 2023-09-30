#include<bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define read(x) for(auto& qw : (x)) cin >> qw;
#define endl "\n"; //para problemas iterativos comentar essa linha
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 998244353;
const ll NO_OPERTATION = -1;
const double eps = 1e-8;
const int MAX = 250000 + 10;
const int LOG = 20;
 
 
ll resp1;
 
 
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<ll> v(n); read(v); sort(all(v));
        map<ll,ll> mapa;
        int qnts = 0;
        for(int i=0;i<n;i++)
        {
            if(mapa[v[i]-1]<=mapa[v[i]])
            {
                mapa[v[i]]++;
                qnts++;
            }
            else{mapa[v[i]]++;}
        }
        cout<<qnts<<endl;
    }
    return 0;
}