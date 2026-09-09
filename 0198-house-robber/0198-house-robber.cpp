class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0], prev2 = 0, curri = 0;

        for(int i = 1; i<n; i++){
            int pick = 0;
            pick = nums[i]; if(i > 1) pick += prev2;
            int notpick = prev;
            curri = max(pick, notpick);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};