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
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int index,number=INT_MIN;
        for(int i=0;i<n;i++){
            if(v[i]>number){
                number=v[i];
                index=i;
            }
        }
        cout<<index+1<<endl;
    }
    return 0;
}
