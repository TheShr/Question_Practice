class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i<n; i++){
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int j = i+1, k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0) j++;
                else if(sum > 0) k--;
                else{
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    
                    ans.push_back(temp);
                    j++; k--;

                    while(j < k && nums[j-1] == nums[j]) j++;
                    while(j < k && nums[k+1] == nums[k]) k--;
                }
            }
        }

        

        return ans;
    }
};