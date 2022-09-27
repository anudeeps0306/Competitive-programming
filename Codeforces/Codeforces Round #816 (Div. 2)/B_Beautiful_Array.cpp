#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       ll n,k,b,s;
       cin>>n>>k>>b>>s;
       if(k*b>s || k*b+n*(k-1)<s){
              cout<<"-1";
       }
        vector<ll>ap(n,0);
       else{
        if(b>=(s)%k){
            ap[0]=s;
            s=0;
        }
        else if(b<(s)%k){
            ap[0]=b;
            s-=b;
        }
        vector<ll>ap(n,0);
        ap[0]=b*k;
        s-=b*k;
        for(int i=1;i<n;++i){
            if(s>0){
                ap[i]=min(s,k-1);
                s-=min(s,k-1);
            }
            else{
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            cout<<ap[i]<<" ";
        } 
       }
        cout<<endl;
    }
    return 0;
}
 
