class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size()/2;
        vector<int> pos;
        vector<int> neg;
        for(int x : nums){
            if(x<=0) neg.push_back(x);
            else pos.push_back(x);
        }
        vector<int> ans;
        for(int i = 0; i<n; i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};