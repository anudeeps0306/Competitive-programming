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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }
    for(auto it : mp){
        if(it.second==n){
            cout<<"NO"<<endl;
            return;
        }
    }
    
        sort(a.begin(),a.end());
        cout<<"YES"<<endl;
        cout<<a[0]<<" "<<a[n-1]<<" ";
        for(int i=1;i<n-1;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;

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