class Solution {
public:
    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adjls, int &ans){
       
        for(auto &it : adjls[node]){
            int u = it.first;
            int w = it.second;

            if(u == parent) continue;

            ans += w;
            dfs(u, node, adjls, ans);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
  
        vector<vector<pair<int, int>>> adjls(n);

        for(auto &it : connections){
            int u = it[0];
            int v = it[1];

            adjls[u].push_back({v, 1});
            adjls[v].push_back({u, 0});

        }
        int ans = 0;
        dfs(0, -1, adjls, ans);

        return ans;
    }
};

// 1 --> 2 --> 0