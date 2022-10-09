#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
// const ll N=3e5;
// ll a[N];

ll gcd(ll x,ll y){
    if(!y) return x;
    return gcd(y,x%y);
}

ll maxSubArray(vector<int> nums) {
        ll m = INT_MIN;
        ll currSum = 0;
        for(int i=0;i<nums.size();i++){
            currSum += nums[i];
            
            if(currSum>m)
                m=currSum;
            
            if(currSum<0)
                currSum=0;
        }
        return m;
}

void solve(){
    int n,k;
    cin>>n>>k;
    string q;
    cin>>q;
    k--;q="."+q+".";
    string b=q;
    for(int j=1;j<=n;j++){
        if(q[j]=='1'){
            b[j]='0';
            if(q[j-1]=='0') b[j-1]='1';
            if(q[j+1]=='0') b[j+1]='1';
    }
    q=b.substr(1,n);
    for(int i=0,x=2147483647;i<n;++i,x++){
        if(q[i]=='1') x=0;
        a[i]=x;
    }

    

    }
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