class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev1 = nums[0], prev2 = 0, curri1 = 0;

        for(int i = 1; i<n-1; i++){
            int pick = 0;
            pick = nums[i]; if(i > 1) pick += prev2;
            int notpick = prev1;
            curri1 = max(pick, notpick);
            prev2 = prev1;
            prev1 = curri1;
        }

        int prev4 = 0, curri2 = 0;
        int prev3 = (n > 1 ) ? nums[1] : nums[0];

        for(int i = 2; i<n; i++){
            int pick = 0;
            pick = nums[i]; if(i > 2) pick += prev4;
            int notpick = prev3;
            curri2 = max(pick, notpick);
            prev4 = prev3;
            prev3 = curri2;
        }
        return max(prev1, prev3);
    }
};