class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // using moore's voring algo
        int el = 0, cnt = 0;
        for(int i = 0; i<nums.size(); i++){
            if(cnt == 0){
                el = nums[i];
                cnt = 1;
            }
            else if(el == nums[i]) cnt++;
            else cnt--;
            
        }

        return el;
    }
};