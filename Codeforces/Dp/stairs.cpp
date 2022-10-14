#include <bits/stdc++.h>
using namespace std;


int fid(int m){
    if(m==0) return 1;
    if(m==1) return 1;
    int left=fid(m-1);
    int right=fid(m-2);
    return left+right;
}
 
int main(){
    int n,max;
    cin>>n;
    cout<<fid(n);
    return 0;
}