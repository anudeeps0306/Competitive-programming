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
        int n,m;
        cin>>n>>m;
        bool condition = (n>=2 && m>=2) && (n>=4  || m>=4);
        if(condition){
            cout<<1<<" "<<1;
        }
        else{
            cout<<n/2+1<<" "<<m/2+1;
        }
        cout<<endl;
    }
    return 0;
}
