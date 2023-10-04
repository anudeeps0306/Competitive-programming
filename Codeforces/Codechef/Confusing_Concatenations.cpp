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
    int n;cin>>n;int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    
    // int k=1,j=0;
    // int a1[n/2],a2[n/2],prev=a[0];
    // a1[0]=a[0];
    int maximum=0;
    for(int i=0;i<n;i++) if(a[i]>a[maximum]) maximum=i;
    if(maximum==0) cout<<-1<<endl;

     // for(int i=1;i<n;i++){
    //     if(a[i]<a[i-1] && k<n/2){
    //         a1[k]=a[i];
    //         k++;
    //     }
    //     else if(a[i]>a[i-1] && j<n/2){
    //         a2[j]=a[i];
    //         j++;
    //     }
    //     else{
    //         if(k>=n/2){
    //             a2[j]=a[i];
    //             j++;
    //         }
    //         else{
    //             a1[k]=a[i];
    //             k++;
    //         }
    //     }
    
    else{
        cout<<maximum<<endl;for(int i=0;i<maximum;i++) cout<<a[i]<<" ";cout<<endl<<n-maximum<<endl;for(int i=maximum;i<n;i++) cout<<a[i]<<" ";cout<<endl;
    }
    // for(int i=1;i<n;i++){
    //     if(a[i]<a[i-1] && k<n/2){
    //         a1[k]=a[i];
    //         k++;
    //     }
    //     else if(a[i]>a[i-1] && j<n/2){
    //         a2[j]=a[i];
    //         j++;
    //     }
    //     else{
    //         if(k>=n/2){
    //             a2[j]=a[i];
    //             j++;
    //         }
    //         else{
    //             a1[k]=a[i];
    //             k++;
    //         }
    //     }
    // }
    // cout<<n/2<<endl;
    // for(int i=0;i<n/2;i++){
    //     cout<<a1[i]<<" ";
    // }
    // cout<<endl<<n/2<<endl;
    // for(int i=0;i<n/2;i++){
    //     cout<<a2[i]<<" ";
    // }
    // cout<<endl;
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