#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,next,sum=0;
    cin>>n;
    int a[n];
    cin>>a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        if(a[i]<=a[i-1]){
            next=a[i-1];
            sum+=a[i-1]-a[i];
        }
        else{
            next=a[i];
        }
    }
    cout<<sum;
    return 0;
}