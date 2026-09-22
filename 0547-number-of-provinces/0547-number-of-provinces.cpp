class Solution {
public:
    void dfs(int node, vector<vector<int>> &edges, vector<int> &vis){
            vis[node] = 1;

            for(int i = 0; i<edges[node].size(); i++){
                if(edges[node][i] == 1 && !vis[i]) dfs(i, edges, vis);
            }
    }
    int findCircleNum(vector<vector<int>>& edges) {
                int V = edges.size();
                vector<int> vis(V, 0);
                int ans = 0;

                for(int i = 0; i<V; i++){
                    if(vis[i] == 0){
                        dfs(i, edges, vis);
                        ans++;
                    }
                }

                return ans;
    }
};