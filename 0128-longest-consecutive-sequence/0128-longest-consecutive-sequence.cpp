class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // 1 2 3 4 100 200
        int n = nums.size();
        int cnt = 0;
        int lastsmall = INT_MIN;
        int ans = 0;
        for(int i = 0; i<n; i++){
            // when nums[i] - 1 == lastsmall
            if(nums[i] - 1 == lastsmall){
                cnt++;
                lastsmall = nums[i];
            }
            else if(nums[i] != lastsmall){
                cnt = 1;
                lastsmall = nums[i];
            }

            ans = max(cnt , ans);
        }

        return ans;
    }
};