#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int mod=1000000007;

int power(int a,int b,int mod){
    a =a % mod;
    long long ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        b>>=1;
        a=(a*a)%mod; 
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        set<ll> v;
        ll maxi=0;
        for(int i=1;i<n;i++){
            ll j;
            cin>>j;
            maxi=max(maxi,j);
            v.insert(j);
        }
        ll ans1=0,ans2=0,count=0;

        for(ll i=1;i<=2*n && count<k ;i++){
            if(v.find(i) == v.end()){
                maxi = max(maxi,i);
                if(count<k-1){
                    ans1+=abs(2*n-i);
                }
                ans2+=abs(maxi-i);              
                count++;
            }
        }
        cout<<ans1<<" "<<ans2<<endl;
        cout<<max(ans1,ans2)<<endl;
    }
    return 0;
}
