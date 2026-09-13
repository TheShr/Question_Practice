class Solution {
public:
    bool func(int idx, int target, vector<int>& arr, vector<vector<int>>& dp){

        if(idx == 0) return (arr[idx] == target);
        if(target == 0) return true;
        if(dp[idx][target] != -1) return dp[idx][target];
        bool nottake = func(idx - 1, target, arr, dp);
        bool take = false;
        if(arr[idx] <= target) take = func(idx-1, target - arr[idx], arr, dp);

        return dp[idx][target] = (take || nottake);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int> (sum/2+1, -1));
        
        return (sum % 2 == 0 ? func(n-1, sum/2, nums, dp) : false);
    }
};