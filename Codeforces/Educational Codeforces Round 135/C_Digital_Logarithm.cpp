#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v1(n),v2(n);
        for(int i=0;i<n;i++){
            cin>>v1[i];
        }
        for(int i=0;i<n;i++){
            cin>>v2[i];
        }
        priority_queue<int> q1(v1.begin(), v1.end());
        priority_queue<int> q2(v2.begin(), v2.end());
        int ans = 0;

        while(!q1.empty()){
            if(q1.top() == q2.top()){
                q1.pop();
                q2.pop();
                continue;
            }
            ++ans;
            if(q1.top() > q2.top()){
                q1.push(to_string(q1.top()).size());
                q1.pop();
            }
            else{
                q2.push(to_string(q2.top()).size());
                q2.pop();
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
