class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mp(1e4+1, -1);
        stack<int> st;
        for(int i = nums2.size()-1; i>=0; i--){

            while(!st.empty() && nums2[i] >= st.top()) st.pop();

            if(!st.empty()) mp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        int n = nums1.size();
        vector<int> ans(n);
        for(int i =0; i<nums1.size(); i++){
            ans[i] = mp[nums1[i]];
        }

        return ans;


    }
};