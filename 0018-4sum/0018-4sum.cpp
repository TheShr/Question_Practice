class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int h = 0; h < n; h++){
            if(h > 0 && nums[h-1] == nums[h]) continue;
            for(int i = h+1; i<n; i++){
                if(i > h+1 && nums[i-1] == nums[i]) continue;
                int j = i+1, k = n-1;
                while(j < k){
                    long long sum = (long long)nums[h] + nums[i] + nums[j] + nums[k];

                    if(sum < target) j++;
                    else if(sum > target) k--;
                    else{
                        vector<int> temp = {nums[h], nums[i], nums[j], nums[k]};
                        
                        ans.push_back(temp);
                        j++; k--;

                        while(j < k && nums[j-1] == nums[j]) j++;
                        while(j < k && nums[k+1] == nums[k]) k--;
                    }
                }
            }

        }

        return ans;
    }
};