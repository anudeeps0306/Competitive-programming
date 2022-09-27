#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,input,ans=0;
    cin>>t;
    for(int i=0;i<t-1;i++){
        cin>>input;
        ans+=input;
    }
    cout<<(t*(t+1))/2-ans;
    return 0;
}
