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
        int n,odd=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%2!=0){
                odd++;
            }
        }
        if(odd == 0){
            cout<<0<<endl;
        }
        else
        cout<<n-odd<<endl;
    }
    
    return 0;
}
