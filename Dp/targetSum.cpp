#include<bits/stdc++.h>

using namespace std;


bool target1(vector<int>& nums, int target,int sum,int pos,vector<vector<int>>& dp){
    if(sum==target){
        return true;
    }
    if(pos>=nums.size()){
        return false;
    }
    if(dp[pos][sum]!=-1){
        return dp[pos][sum];
    }
    int taken;
    if(nums[pos]+sum <= target){
        taken = nums[pos]+sum;
        if(target1(nums,target,taken,pos+1,dp)){
            dp[pos][sum] = 1;
            return true;
        }
    }
    if(target1(nums,target,sum,pos+1,dp)){
        dp[pos][sum] = 1;
        return true;
    }
    dp[pos][sum] = 0;
    return false;
}

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int target;
    cin>>target;
    vector<vector<int>> dp(n+1, vector<int>(target+1, -1)); 
    cout<<target1(nums,target,0,0,dp);
}