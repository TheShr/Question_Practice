class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // gotta make use of prefix sum , hashmap !!

        unordered_map<int, int> mp;
        int cnt = 0;
        mp[0] = 1;
        int sum = 0;
        int n = nums.size();
        for(int r = 0; r<n; r++){
            sum += nums[r];
            int rem = sum - k;
            cnt += mp[rem];
            mp[sum]++;
        }
        return cnt;
    }
};