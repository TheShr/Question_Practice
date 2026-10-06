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
    int minCostConnectPoints(vector<vector<int>>& points) {
        // based on mst
        int ans =0;
        int n = points.size();
        DisjointSet ds(n);
        vector<pair<int, pair<int,int>>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int cost = abs(points[i][0] - points[j][0])
                    + abs(points[i][1] - points[j][1]);

                edges.push_back({cost, {i, j}});
            }
        }

        sort(edges.begin(), edges.end());

        for (auto &edge : edges) {

            int cost = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if (ds.findParent(u) != ds.findParent(v)) {

                ans += cost;
                ds.unionBySize(u, v);
            }
        }

        return ans;
    }
};