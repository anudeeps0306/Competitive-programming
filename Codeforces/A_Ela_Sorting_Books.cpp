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
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<int> a(26,0);
        //  for(int i=0;i<26;i++){
        //     cout<<a[i];
        // }
        for(auto it : s){
            a[it-'a']++;
        }
        string str="";
        int count=0,prev=0;
        for(int i=0;i<26 && count<m ;i++){
            if(a[i]>=m){
                bool flag= true;
                int j=i+1;
                while(flag && j<26 && count<m){
                    if(a[j]==0){
                        str+=char(97+j);
                        flag=false;
                        count++;
                    }
                    j++;
                }
            }
            else{
                a[i]=m-a[i];
                // cout<<"//"<<m-a[i]<<endl;
                while(a[i]>0 && count<m){
                    str+=char(97+i);
                    count++;
                    a[i]--;
                }
            }
            prev=a[i];
        }
        cout<<str<<endl;
    }
    return 0;
}
 
