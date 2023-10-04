#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,x;
    cin>>n>>x;

    vector<int> a(n);

    

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a.begin(),a.end());

    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }

    // cout<<endl;

    int start=0;
    int cnt=0;
    int end = n-1;

    while(start<=end){
        if(a[start]+a[end]<=x){
            start++;
            end--;
        }
        else{
            end--;
        }
        cnt++;
    }
    cout<<cnt<<endl;


    

    return 0;
}