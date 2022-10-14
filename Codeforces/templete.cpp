#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll sqaureRoot(ll i){
    ll start=0,end=1e10;

    while(start<=end){
        ll mid = start + (end-start)/2;
        if(mid*mid > i) end = mid;
        else start = mid+1;
    }
    return start;
}


void solve(){
    ll l,r;
    cin>>l>>r;
    cout<<sqaureRoot(500);
    // for(ll i=l;i<=r;i++){
    //     if(sqaureRoot(i)%i==0){

    //     }
    // }
}

int main(){
    int t;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}
