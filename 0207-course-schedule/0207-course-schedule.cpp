class Solution {
public:
    bool dfs(vector<vector<int>> &adjLs, int node,vector<int> &vis, vector<int> &pathvis){
        
        vis[node] = 1;
        pathvis[node] = 1;

        for(int it : adjLs[node]){
            if(!vis[it]){
                if(dfs(adjLs, it, vis, pathvis) == true) return true;    
            }
            else if(pathvis[it] == 1) return true;
        }

        pathvis[node] = 0;
        return false;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0), pathvis(numCourses, 0);
        vector<vector<int>> adjLs(numCourses);
        for(auto &it : prerequisites){
            int u = it[0];
            int v = it[1];
            //adjLs[u].push_back(v);
            adjLs[v].push_back(u);
        }
        for(int i = 0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(adjLs, i, vis, pathvis) == true) return false;
            }
        }
        return true;
    }
};