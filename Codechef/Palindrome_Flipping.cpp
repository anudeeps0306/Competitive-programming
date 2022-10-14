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
        string s;
        cin>>s;
        int k = s.size();
        int count=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                count++;
            }
        }
        if(k%2==0){
            if(count%2==0) cout<<"YES";
            else cout<<"NO";
        }
        else{
            cout<<"YES";
        }
        cout<<endl;
    }
    return 0;
}
