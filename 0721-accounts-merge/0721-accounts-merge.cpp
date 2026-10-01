class DisjointSet {
    vector<int> parent, rank, size;
public:
    DisjointSet(int n) {

     parent.resize(n+1, 0);
     size.resize(n+1, 0);
     for(int i = 0; i<=n; i++){
        parent[i] = i;
        size[i] = 1;
     }
     rank.resize(n+1, 0);

    }
    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    bool find(int u, int v) {
        if(findParent(u) == findParent(v)) return true;
        return false;
    }

    void unionByRank(int u, int v) {
     int ulp_u = findParent(u);
     int ulp_v = findParent(v);
     if(ulp_u == ulp_v) return;
     if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
     else if(rank[ulp_u] > rank[ulp_v]) parent[ulp_v] = ulp_u;
     else{
        parent[ulp_v] = ulp_u;
        rank[ulp_u]++;
     }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        map<string, int> mp;
        for(int i = 0; i<n; i++){
            for(int j = 1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                else{
                    ds.unionByRank(i, mp[mail]);
                }
            }
        }

        vector<vector<string>> mergedMail(n);
        for(auto &it : mp){
            string mail = it.first;
            int node = ds.findParent(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i = 0; i<n; i++){
            if(mergedMail[i].size() == 0) continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto &it : mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;


    }
};