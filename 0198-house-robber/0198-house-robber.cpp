class Solution {
public:
    int func(vector<int> &nums, int idx, vector<int> &dp){
        if(idx == 0) return nums[0];
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int pick = INT_MIN;
        pick = nums[idx] + func(nums, idx - 2, dp);
        int notpick = func(nums, idx-1, dp);

        return dp[idx] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n+1, -1);
        return func(nums, n-1, dp);
    }
};