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
        int n;
        cin>>n;
        int a[n];
        map<int,int> m;
        for(int i=0;i<n;i++){
            cin>>a[i];
            m[a[i]]++;
        }
        int sum=0,mini;
        for(auto it : m){
            sum=max(sum,it.second-1);
        }
        cout<<sum<<endl;
    }
    
    return 0;
}
