class Solution {
public:
    int func(int mid, vector<int>& nums, int k){
        int cnt = 1, sum = 0;
        for(int i = 0; i<nums.size(); i++){
            if(sum + nums[i] > mid){
                cnt++;
                sum = nums[i];
            }
            else sum += nums[i];
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(),0);

        while(low <= high){
            int mid = (low + high)/2;
            if(func(mid , nums , k) <= k){
                high = mid -1;
            }
            else low = mid + 1;
        }
        return low;
    }
};

/*

array is given divde it into non subarrays such that largest sum of any subarr is min

4 5 6 7 8 9 
m = 6
*/