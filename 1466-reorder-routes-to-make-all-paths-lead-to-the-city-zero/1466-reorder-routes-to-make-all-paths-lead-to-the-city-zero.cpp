class Solution {
public:
    void dfs(int node, int parent, vector<int> &vis, vector<vector<pair<int, int>>>& adjls, int &ans){
        vis[node] = 1;
        for(auto &it : adjls[node]){
            int u = it.first;
            int w = it.second;

            if(u == parent) continue;

            ans += w;
            dfs(u, node, vis, adjls, ans);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> vis(n);
        vector<vector<pair<int, int>>> adjls(n);

        for(auto &it : connections){
            int u = it[0];
            int v = it[1];

            adjls[u].push_back({v, 1});
            adjls[v].push_back({u, 0});

        }
        int ans = 0;
        dfs(0, -1, vis, adjls, ans);

        return ans;
    }
};

// 1 --> 2 --> 0