class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        for(int it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i =0 ; i<isConnected.size();i++){
            for(int j =0; j<isConnected.size(); j++){
                if(isConnected[i][j] == 1&& i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
         vector<int> vis(n,0);
         int cnt = 0;
         for(int i=0; i<adj.size(); i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adj, vis);
            }
         }
        return cnt;
    }
};