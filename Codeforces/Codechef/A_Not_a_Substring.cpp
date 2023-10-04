class Solution {
private:
    void help(vector<vector<int>>& dp,vector<int> nums){
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < 4; j++) {
                if(j == nums[i]){
                    dp[i+1][j] = dp[i][j] + 1;
                }
                else{
                    dp[i+1][j] = dp[i][j];
                }
            }
        }
    }
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size(),ans = INT_MAX;
        vector<vector<int>> dp(n + 1, vector<int>(4, 0));

        help(dp,nums);
       

        for (int i = 0; i <= n; i++) {
            for (int j = i; j <= n; j++) ans = min(ans, n - (dp[i][1]+dp[j][2]+dp[n][3]-(dp[i][2]+v[j][3])));
        }

        return ans;
    }
};