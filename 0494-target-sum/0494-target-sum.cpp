class Solution {
public:
    int func(int idx, int s2, vector<int> &nums){
        if(idx == 0){
            if(nums[0] == 0 && s2 == 0) return 2;
            if(nums[0] == s2 || s2 == 0) return 1;
            return 0;
        }

        int pick = 0;
        if(nums[idx] <= s2) pick = func(idx-1, s2 - nums[idx], nums);
        int notpick = func(idx-1, s2, nums);

        return pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int s2 = (sum-target)/2;
        if((sum-target) % 2 != 0|| sum - target < 0) return 0;
        
        vector<vector<int>> dp(n, vector<int> (s2+1, 0));
        if(nums[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;

        if(nums[0] <= s2 && nums[0] != 0) dp[0][nums[0]] = 1;
        


        for(int i = 1; i<n; i++){
            for(int j = 0; j<= s2; j++){
                int pick = 0;
                if(nums[i] <= j) pick = dp[i-1][j-nums[i]];
                int notpick = dp[i-1][j];

                dp[i][j] = (pick + notpick);
            }
        }
        return dp[n-1][s2];
    }
};