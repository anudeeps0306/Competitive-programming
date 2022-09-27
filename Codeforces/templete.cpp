#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int m,least=INT_MAX,differnce=0; cin>>m;
        vector<int> v(m);
        for(int i=0;i<m;i++) cin>>v[i];
        sort(v.begin(),v.end());
        for(int i=0 ; i<m-2 ; i++){
            differnce = v[i+1]+v[i+2]-v[i+1]-v[i];
            if(differnce < least) least = differnce;
        }
        cout<<least<<"\n";
    }
    return 0;
}
