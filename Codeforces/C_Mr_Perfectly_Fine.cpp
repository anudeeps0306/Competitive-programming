#include<bits/stdc++.h>
using namespace std;

bool getot(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int,int>> vec1, vec2;
    vector<int> vec3;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        string s;
        cin >> s;
        if(s[1]=='1') vec2.push_back({x,i});
        if(s[0]=='1') vec1.push_back({x,i});
        if(s[0]=='1' && s[1]=='1') vec3.push_back(x);
        
    }

    sort(vec1.begin(),vec1.end(),getot);
    sort(vec3.begin(),vec3.end());
    sort(vec2.begin(),vec2.end(),getot);

    if(vec1.size()==0 || vec2.size()==0){
        cout << -1 << endl;
        return;
    }
    else{
        if(vec1[0].second == vec2[0].second){
            cout << vec1[0].first << endl;
        }
        else{
            if(vec3.size()>0 && vec1[0].first + vec2[0].first > vec3[0])
                cout << vec3[0] << endl;
            else
                cout << vec1[0].first + vec2[0].first << endl;
        }
    }
}

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
