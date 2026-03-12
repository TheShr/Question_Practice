class Solution {
public:
    bool isCycle(int node, vector<vector<int>>& adjLs, vector<int> &vis, vector<int> &pathvis){
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto &it : adjLs[node]){
            if(!vis[it]){
                if(isCycle(it, adjLs, vis, pathvis)) return true;
            }
            else if(pathvis[it]) return true;
        }
       
        pathvis[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // nodes  are given convert to adjcy list!
        vector<vector<int>> adjLs(numCourses);
        for(auto &it : prerequisites){
            int u = it[0];
            int v = it[1];
            //adjLs[u].push_back(v);
            adjLs[v].push_back(u);
        }
        vector<int> vis(numCourses,0);
        vector<int> pathvis(numCourses,0);
        // if cycle false
        for(int i =0; i<numCourses; i++){
            if(!vis[i]){
                if(isCycle(i, adjLs, vis, pathvis)) return false;
            } 
        }
        return true;
    }
};