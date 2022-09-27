#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    cout<<t<<" ";
    while(t!=1){
        if(t%2==0){
            t=t/2;
        }
        else{
            t=t*3+1;
        }
        cout<<t<<" ";
    }
    return 0;
}
