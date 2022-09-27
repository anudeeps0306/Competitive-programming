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
            int n,max=INT_MIN,min=INT_MAX;
            cin>>n;
            vector<int> a(n);
            map<int,int> m;
            for(int i=0;i<n;i++){
                cin>>a[i];
                m[a[i]]++;
            }
            for(int i=0;i<n;i++){
                if(a[i]>max){
                    max=a[i];
                }
                if(a[i]<min){
                    min=a[i];
                }
            }
            if(max==min){
                cout<<n-m[max];
            }
            else{
                cout<<n-m[max]-m[min];
            }
            cout<<endl;
        }
        return 0;
    }
