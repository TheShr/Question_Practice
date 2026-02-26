class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size() , left = 0, ans = 0;
        unordered_set<int> st;
        for(int right = 0; right<n; right++){
            while(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};