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

void solve(){
    int n;
    cin>>n;
    string s,t="";
    cin>>s;
    int j=0,k=n-1;
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(s[j]=='0'){
                t="0"+t;
            }
            else{
                t=t+"1";
            }
            j++;
        }
        else{
            if(s[k]=='1'){
                t="1"+t;
            }
            else{
                t=t+"0";
            }
            k--;
        }
    }
    cout<<t<<endl;
}    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}