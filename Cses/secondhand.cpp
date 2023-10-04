#include<bits/stdc++.h>

using namespace std;

void solve(int t){
    int n,k;
    cin>>n>>k;

    vector<int> arr(n);
    map<int,int> mp;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }

    int cnt=0;

    int a=0,b=0;

    for(auto it : mp){
        if(it.second>2){
            cout<<"Case #"<<t<<": "<<"NO\n";
            return;
        }
        if(it.second==2){
            a++;
            b++;
        }
        else{
            if(a>b){
                b++;
            }
            else{
                a++;
            }
        }
    }
    if(a>k || b>k){
        cout<<"Case #"<<t<<": "<<"NO\n";
        return;
    }
    cout<<"Case #"<<t<<": "<<"YES\n";
}

int main(){
    // #ifndef ONLINE_JUDGE
  
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);
  
    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
  
    // #endif
    int t;
    cin>>t;

    for(int i=1; i<=t ;i++){
        solve(i);
    }

    return 0;
}
