class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0, zeroes = 0, l = 0;
        for(int r =0; r<n; r++){
            if(nums[r] == 0) zeroes++;
            while(zeroes > k){
                if(nums[l] == 0) zeroes--;
                l++;
            }
            if(zeroes <= k) maxlen = max(maxlen, r-l+1);
        }

        return maxlen;
    }
};