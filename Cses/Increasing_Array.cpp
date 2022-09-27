#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n,sum=0;
    cin>>n;
    long long a[n];
    cin>>a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]){
            sum+=(a[i-1]-a[i]);
            a[i]=a[i-1];
        }
    }
    cout<<sum;
    return 0;
}