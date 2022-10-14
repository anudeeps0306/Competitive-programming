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
    int n;
    cin>>n;
    int a[n],b[n],count1=0,count2=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1) count1++;
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(b[i] == 1) count2++;
    }
    int change=0;
    for(int i=0;i<n;i++){
        if(a[i] != b[i]) change++;
    }
    int dif = abs(count1-count2);
    // cout<<change<<" "<<dif<<endl;
    if(change == dif) cout<<dif;
    else{
        cout<<dif+1;
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}
