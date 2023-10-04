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

    vector<pair<int,int>> v;

    for(auto it:m){
        v.push_back(it);
    }

    cout<<f(v)<<endl;

    
    

    

    return 0;
}