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
        ll a,a1=0,b1=0,sum=0,sum1=0,sum2=0;
        cin>>a;
        ll ar1[a],ar2[a];
        for(int i=0;i<a;i++){
            cin>>ar1[i];
            sum1+=ar1[i];
        }
        for(int i=0;i<a;i++){
            cin>>ar2[i];
            sum2+=ar2[i];
        }
        if(sum1!=sum2){
            cout<<-1;
        }
        else{
            for(int i=0;i<a;i++){
                sum+=abs(ar2[i]-ar1[i]);
            }
            cout<<sum/2;
        }
        cout<<endl;
    }
    
    return 0;
}
