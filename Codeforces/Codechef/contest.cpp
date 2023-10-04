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
        if(n>2){
            for(int i=n-1;i>0;i--){
                cout<<i<<" ";
            }
            cout<<n<<" ";
        }
        cout<<endl;  
    }
    
    return 0;
}
