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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int m = edges[0].size();

        DisjointSet ds(n*m);

        for(auto &it : edges){
            int u = it[0];
            int v = it[1];

            if(ds.findParent(u) != ds.findParent(v)){
                ds.unionBySize(u, v);
            }
            else return {u,v};
        }
        return {};
    }
};  