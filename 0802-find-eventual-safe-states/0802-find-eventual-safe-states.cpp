class Solution {
public:
    bool dfs(vector<int> &vis, vector<int> &pathvis, vector<vector<int>>& graph, int node, vector<int> &safenode){
        vis[node] = 1;
        pathvis[node] = 1;
        safenode[node] = 0;
        for(auto &it: graph[node]){
            if(!vis[it]){
                if(dfs(vis, pathvis, graph, it, safenode) == true){
                    safenode[it] = 0;
                    return true;
                }
            }else if(vis[it] && pathvis[it]){
                safenode[it] = 0;
                return true;
            }
        }
        safenode[node] = 1;
        pathvis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0), pathvis(n, 0);
        vector<int> safenode(n, 0), ans;

        for(int i = 0; i<n; i++){
            if(!vis[i]) dfs(vis, pathvis, graph, i, safenode);
        }
        for(int i = 0; i<n; i++){
            if(safenode[i]) ans.push_back(i);
        }

        return ans;
    }
};