class Solution {
public:
    bool iscyclic(int node, vector<int> &vis, vector<vector<int>> &adjLs, vector<int> &pathvis, vector<int> &ans){
        vis[node] = 1;
        pathvis[node] = 1;

        for(auto &it : adjLs[node]){
            if(!vis[it]){
                if(iscyclic(it, vis, adjLs, pathvis, ans)) return true;
                
            }
            else if(pathvis[it]) return true;
        }
        pathvis[node] = 0;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
        vector<int> pathvis(numCourses,0);
        vector<vector<int>> adjLs(numCourses);
        vector<int> ans;
        for(auto &it : prerequisites){
            int u = it[0];
            int v = it[1];
            adjLs[v].push_back(u);
        }
        for(int i = 0; i<numCourses; i++){
            if(!vis[i]){
                if(iscyclic(i, vis, adjLs, pathvis, ans)){
                    return {};
                }
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};