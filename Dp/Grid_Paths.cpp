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
    

    vector<vector<char>> v(n,vector<char>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }

    vector<vector<int>> dp(n,vector<int>(n,0));

    dp[0][0]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]=='*'){
                dp[i][j]=0;
            }
            else{
                if(i-1>=0){
                    dp[i][j]+=dp[i-1][j];
                    dp[i][j]%=MOD;
                }
                if(j-1>=0){
                    dp[i][j]+=dp[i][j-1];
                    dp[i][j]%=MOD;
                }
            }
        }
    } 
    cout<<dp[n-1][n-1]<<endl;
    return 0;
}