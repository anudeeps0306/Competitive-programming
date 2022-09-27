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
        if(n%2==0){
            for(int i=1;i<=n-2;i++){
                if(i%2==0){
                    cout<<i-1<<" ";
                }

                else{
                    cout<<i+1<<" ";
                }       
            }
            cout<<n-1<<" "<<n;
        }
        else{
            cout<<1<<" ";
            for(int i=2;i<=n-2;i++){
                if(i%2==0){
                    cout<<i+1<<" ";
                }

                else{
                    cout<<i-1<<" ";
                }
            }
            cout<<n-1<<" "<<n;
        }
        cout<<endl;
    }
    return 0;
}
