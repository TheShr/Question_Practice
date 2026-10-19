class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, el1 = INT_MIN, el2 = INT_MIN;
        int n = nums.size();
        for(int i = 0; i< nums.size(); i++){
            if(cnt1 == 0 && el2 != nums[i]){
                el1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0 && el1 != nums[i]){
                el2 = nums[i];
                cnt2 = 1;
            }

            else if(el1 == nums[i]) cnt1++;
            else if(el2 == nums[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        int check1 =0, check2= 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == el1) check1++;
            if(nums[i] == el2) check2++;
        }
        vector<int> ls;
        if(check1 >= n/3+1) ls.push_back(el1);
        if(check2 >= n/3+1) ls.push_back(el2);

        sort(ls.begin(), ls.end());

        return ls;
    }
};