#include <bits/stdc++.h>
using namespace std;


const int MOD = (int)(1e9+7);



// void f(int n,int count,int &ans){
//     if(n==0){
//         ans=min(ans,count);
//         return;
//     }
//     if(n<0){
//         return;
//     }
//     int temp=n;
//     while(temp>0){
//         if(temp%10!=0)
//         f(n-temp%10,count+1,ans);
//         temp/=10;
//     }
// }

int main(){
    int n;
    cin>>n;
    

    vector<int> dp(n+1,INT_MAX);


    for(int i=0;i<=min(9,n);i++){
        dp[i]=1;
    }
    if(n<=9){
        cout<<dp[n]<<endl;
        return 0;
    }
    for(int i=10;i<=n;i++){
        int temp=i;
        while(temp>0){
            if(temp%10!=0)
            dp[i]=min(dp[i],dp[i-temp%10]+1);
            temp/=10;
        }
    }

    dp[n]==INT_MAX?cout<<-1:cout<<dp[n];
    return 0;
}