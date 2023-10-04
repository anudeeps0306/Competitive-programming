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
    int m;
    cin>>m;
    vector<int> b(m);
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    ll maximum=INT_MIN,sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>maximum){
            maximum=sum;
        }
    }
    sum=0;
    for(int i=n-1;i>=0;i--){
        sum+=a[i];
        if(sum>maximum){
            maximum=sum;
        }
    }
    for(int i=0;i<m;i++){
        if(b[i]>0){
            maximum+=b[i];
        }
    }
    maximum = max(maximum,maxSubArray(a));

    cout<<maximum<<endl;
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