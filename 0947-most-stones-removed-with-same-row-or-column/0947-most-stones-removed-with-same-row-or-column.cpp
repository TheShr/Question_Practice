class DisjointSet {
    
public:
    vector<int> parent, rank, size;
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int mxrow = 0, mxcol = 0;
        for(auto &it : stones){
            mxrow = max(it[0], mxrow);
            mxcol = max(it[1], mxcol);
        }

        DisjointSet ds(mxrow+mxcol+1);
        set<int> s;
        for(auto &it : stones){
            int node1 = it[0];
            int node2 = it[1] + mxrow + 1;

            ds.unionBySize(node1, node2);
            s.insert(node1);
            s.insert(node2);
        }
        set<int> components;
        for(auto &it : s){
            components.insert(ds.findParent(it));
        }
        
        return n - components.size();
    }
};

/*
every component will have one '1' remaining 
1 1 0
1 0 1 
0 1 1

cnt = 1
0 1 
1 1 

*/