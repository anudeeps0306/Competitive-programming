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
        ll n,m;
        cin>>n>>m;
        if(n==1 && m==1){
            cout<<"0\n";
            continue;
        }
        if(n>m){
            cout<<n+(m-1)*2<<endl;
        }
        else{
            cout<<m+(n-1)*2<<endl;
        }
    }
    return 0;
}
 
