class Solution {
public:
    int timer = 1;
    void dfs(int node, int parent, vector<vector<int>>& adjLs, vector<int> &vis, vector<vector<int>>&ans, vector<int> &low, vector<int> &tin){
        vis[node] = 1;
        low[node] = tin[node] = timer;
        timer++;
        for(auto &it : adjLs[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it, node, adjLs, vis, ans, low, tin);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]) ans.push_back({it, node});
            }
            else{
                low[node] = min(low[node], tin[it]);
            }
        }
        
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> vis(n);
        vector<int> low(n);
        vector<int> tin(n); // dfs time of insertion
        vector<vector<int>> ans;
        vector<vector<int>> adjLs(n);
        for(auto &it : connections){
            int u = it[0];
            int v = it[1];

            adjLs[u].push_back(v);
            adjLs[v].push_back(u);
        }
        dfs(0, -1, adjLs, vis, ans, low, tin);

        return ans;
    }
};