class Solution {
public:
    bool func(int mid , vector<int>& nums, int threshold){
        int k = 0;
        for(int i =0; i<nums.size(); i++){
            k += (nums[i] + mid - 1) / mid;
        }
        if(k <= threshold) return true;
        else return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int low = 1, high = mx;
        while(low <= high){
            int mid = (low + high)/2;
            if(func(mid, nums, threshold)){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};

// sum = 17