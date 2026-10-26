class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Optimal Soln by using set
        unordered_set<int> s;
        int n = nums.size();
        if(n == 0) return 0;
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            s.insert(nums[i]);
        }

        for(int it : s){
            if(s.find(it-1) != s.end()) continue;
            else{
                int x = it;
                while(s.find(x) != s.end()){
                    x++;
                    cnt++;
                    ans = max(ans, cnt);
                }
                cnt = 0;
            }
        }

        return ans;
    }
};