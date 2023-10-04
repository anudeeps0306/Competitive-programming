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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        if(n==k){
            cout<<2<<endl;
        }
        else if(k%2==1){
            cout<<power(2,n,mod)<<endl;
        }
        else{
            cout<<power(2,n-1,mod)<<endl;
        }
    }
    return 0;
}
