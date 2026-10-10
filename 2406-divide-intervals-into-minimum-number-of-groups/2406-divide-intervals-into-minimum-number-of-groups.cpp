class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // create a map<int, pair<int,int> mp    {time, Arrival / Departure}

        map<int, pair<int, int>> mp;
        
        int cnt = 0;
        for(auto &it : intervals){
            int st = it[0];
            int end = it[1];

            mp[st].first++;
           
            mp[end].second++;
          
        }
        int ans = 0;
        for(auto &it : mp){
            cnt += it.second.first;
            ans = max(cnt , ans);
            cnt -= it.second.second;
        }

        return ans;
        
    }
};