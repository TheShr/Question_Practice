class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxdist = 0;
        int n = nums.size();
        for(int i = 0; i<nums.size(); i++){
            if(i > maxdist) return false;
            maxdist = max(maxdist, i + nums[i]);
            if(maxdist >= n-1) return true;
        }

        return true;
    }
};