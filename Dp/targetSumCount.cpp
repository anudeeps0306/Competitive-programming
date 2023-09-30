#include<bits/stdc++.h>

using namespace std;


int target1(vector<int>& nums, int target,int mini,int maxi,int pos){
    
    
    if(maxi+mini > target && pos>=nums.size()){
        return 0;
    }

    cout<<"yes"<<endl;


    
    int taken=0,not_taken=0;
   
    not_taken = target1(nums,target,mini,maxi,pos+1);

    maxi = max(maxi,nums[pos]);
    mini = min(mini,nums[pos]);

    if(maxi+mini <= target){
        taken = target1(nums,target,mini,maxi,pos+1);
    }

    cout<<taken<<" "<<not_taken<<endl;

    return 1+taken+not_taken;
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

    cout<<target1(nums,target,INT_MAX,INT_MIN,0);
}