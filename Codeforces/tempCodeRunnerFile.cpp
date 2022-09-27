#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,k,input;
        cin>>n>>k;
        map<int,int> m;
        for(int i=0;i<n;i++){
            cin>>input;
            m[input]++;
        }
        if(n>2*k){
            cout<<"Case #"<<i<<": "<<"NO";
        }
        else{
            bool flag=true;
            for(auto it : m){
                if(it.second>2){
                    flag=false;
                }
            }
            if(flag==true){
                cout<<"Case #"<<i<<": "<<"YES";
            }
            else{
                cout<<"Case #"<<i<<": "<<"NO";
            }
        }
        cout<<endl;
    }
    return 0;
}
