#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll N=3e5;
ll a[N];

ll gcd(ll x,ll y){
    if(!y) return x;
    return gcd(y,x%y);
}

ll solve(){
        ll n;
        cin>>n;
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll gcd_1=0;
        ll gcd_2=0;
        for(ll i=1;i<n;i=i+2){
            gcd_1=__gcd(gcd_1,a[i]);
        }
        bool flag=true;
        for(ll i=0;i<n;i+=2){
            if(a[i]%gcd_1==0){
                flag=false;
                break;
            }
        }
        if(flag){
            return gcd_1;
        }
        for(ll i=0;i<n;i=i+2){
            gcd_2=__gcd(gcd_2,a[i]);
        }
        flag=true;
        for(ll i=1;i<n;i=i+2){
            if(a[i]%gcd_2==0){
                flag=false;
                break;
            }
        }
        if(flag){
            return gcd_2;
        }
        return 0;
    }    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}