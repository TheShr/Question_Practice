class Solution {
public:
    bool dfs(vector<vector<int>> &adjLs, stack<int> &st, vector<int> &vis, int node, vector<int> &pathvis){
        vis[node] = 1;
        pathvis[node] = 1;

        for(auto &it : adjLs[node]){
            if(!vis[it]){
                if(dfs(adjLs, st, vis, it, pathvis) == true) return true;
            }
            else if(vis[it] && pathvis[it]) return true;   
        }
        pathvis[node] = 0;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses), ans;
        vector<int> pathvis(numCourses);
        stack<int> st;
        vector<vector<int>> adjLs(numCourses);

        for(int i = 0; i< prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjLs[v].push_back(u);
        }

        for(int i = 0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(adjLs, st, vis, i, pathvis) == true) return {};
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};