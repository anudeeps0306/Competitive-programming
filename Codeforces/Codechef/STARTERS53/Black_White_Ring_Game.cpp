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
        int n,max=INT_MAX;
        cin>>n;
        int array[n];
        for(int i=0;i<n;i++){
            cin>>array[i];
        }
        vector<int> count(2);
        for(int i=0;i<2;i++){
            count[i]=0;
        }
        for(int i=0;i<n-1;i++){
            if(array[i+1]==array[i]){
                count[array[i]]++;
            }
        }
        if(array[0]==array[n-1]){
            count[array[0]]++;
        }
        for(auto it:count){
            max=min(max,it);
        }
        if(max%2==0){
            cout<<"Bob";
        }
        else{
            cout<<"Alice";
        }
        cout<<endl;
            }
    
    return 0;
}
