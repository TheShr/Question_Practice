class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<int>> mp;
        vector<string> s = strs;
        for(int i = 0; i<strs.size(); i++){
            sort(s[i].begin(), s[i].end());
            mp[s[i]].push_back(i);
        }

        for(auto &it : mp){
            
            vector<string> temp;
            for(int i = 0; i<it.second.size(); i++){
                int idx = it.second[i];
                temp.push_back(strs[idx]);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};