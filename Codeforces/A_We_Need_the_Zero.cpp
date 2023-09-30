#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;

    while (t--){
        int n;
        cin>>n;
        
        int a[n];
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            ans^=a[i];
        }

        if(ans==0){
            cout<<0<<endl;
        }
        else if(n%2!=0){
            cout<<ans<<endl;
        }
        else{
            cout<<-1<<endl;
        }


    }
        
    return 0;
}
