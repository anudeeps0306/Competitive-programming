#include<bits/stdc++.h>

using namespace std;

int main(){


    vector<pair<int,int>> v;

    int n;
    cin>>n;


    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }

    sort(v.begin(),v.end());

    // for(auto it : v){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    cout<<upper_bound(v.begin(),v.end(),make_pair(3,INT_MAX))-v.begin()<<endl;

    return 0;
}