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
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int b[n],ans1,ans2,prev;
        bool flag=true;
        b[0]=a[0];
        prev=a[0];

        for(int i=1;i<n;i++){
            ans1=prev+a[i];
            ans2=prev-a[i];
            if(ans1==ans2 || ans2<0){
                b[i]=ans1;
            }
            else{
                flag=false;
                break;
            }
            prev=b[i];
        }
        if(flag==false){
            cout<<-1;
        }
        else{
            for(int i=0;i<n;i++){
                cout<<b[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
