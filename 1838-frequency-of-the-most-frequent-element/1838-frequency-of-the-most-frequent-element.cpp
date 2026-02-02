class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long n = nums.size();
        long long sum = 0, l = 0, ans = 1;
        for(int r = 0; r<n; r++){
            sum+=nums[r];
            while((long long)nums[r]*(r-l+1)-sum > k){
                sum-=nums[l];
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};