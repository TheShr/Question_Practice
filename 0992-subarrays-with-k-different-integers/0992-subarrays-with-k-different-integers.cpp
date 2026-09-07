class Solution {
public:
    int func(vector<int>& nums, int k){
         int n = nums.size(), ans = 0, l = 0, cnt = 0;
        unordered_map<int, int> mp;
        for(int r = 0; r<n; r++){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
                
            }
            if(mp.size() <= k) ans += (r-l+1);
            
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return func(nums, k) - func(nums, k-1);
    }
};