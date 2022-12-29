#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    int temp,pos;
    for(int i=0 ; i<n;i++){
        cin>>a[i];
    }
    temp=a[0],pos=1;

    // for(auto it : a) cout<<it<<" ";

    
    for(int i=1;i<a.size();i++){
        if(a[i] != temp){
             cout<<a[i];
            temp = a[i];
            swap(a[i],a[pos]);
            pos++;
            // cout<<a[i]<<" "<<temp;
        }

        cout<<temp;
        // cout<<a[i]<<" "<<temp;
    }
  

    for(int i=0;i<=pos;i++) cout<<a[i]<<" ";
   
    return 0;
}