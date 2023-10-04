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
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        bool can = 1;
        int ans = 0;
        for(int i=(n-1)/2;i>=0;--i){
            a[i]+=ans;
            int need = a[n-i-1] - a[i];
            can &= (need>=0);
            ans+=need;
        }
        if(can){
            cout<<ans<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}
