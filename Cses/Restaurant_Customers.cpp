#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    
    map<int,int> m;

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;

        m[a]++;
        m[b+1]--;
    }

    int ans=0;

    int cnt=0;

    for(auto it:m){
        cnt+=it.second;
        if(cnt > ans){
            ans = cnt;
        }
    }

    cout<<ans<<endl;

    
    

    

    return 0;
}