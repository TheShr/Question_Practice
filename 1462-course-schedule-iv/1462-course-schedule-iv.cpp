class Solution {
public:

    bool dfs(int node, int target, vector<vector<int>> &adjls){
       
        for(auto &it : adjls[node]){
            if(dfs(it , target, adjls) == true) return true;
            else if(it == target) return true;
        }

        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<vector<int>> adjls(n);
        vector<bool> ans;
        for(auto &it : prerequisites){
            int u = it[0];
            int v = it[1];

            adjls[u].push_back(v);
        }

        for(auto &it : queries){
            int st = it[0];
            int target = it[1];
            bool temp = dfs(st, target, adjls);
            ans.push_back(temp);
        }

        return ans;
    }
};


// 1 2 0