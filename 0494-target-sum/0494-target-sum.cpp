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
        return func(n-1, s2, nums);
    }
};