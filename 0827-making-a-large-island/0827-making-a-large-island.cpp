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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        for(int r = 0; r<n; r++){
            for(int c = 0; c < n; c++){

                int dr[] = {0 , 0, -1 , 1};
                int dc[] = {1, -1, 0, 0};

                if(grid[r][c] == 1){
                    for(int k = 0; k<4; k++){
                        int nrow = r + dr[k];
                        int ncol = c + dc[k];

                        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1){
                            int node1 = n*r + c;
                            int node2 = nrow*n + ncol;

                            if(ds.findParent(node1) != ds.findParent(node2)){
                                ds.unionBySize(node1, node2);
                            }
                        }
                    }
                }
            }
        }
        int mx = INT_MIN;
        for(int r = 0; r<n; r++){
            for(int c = 0; c < n; c++){

                int dr[] = {0 , 0, -1 , 1};
                int dc[] = {1, -1, 0, 0};
   
                if(grid[r][c] == 0){
                    set<int> s;
                    for(int k = 0; k<4; k++){
                        int nrow = r + dr[k];
                        int ncol = c + dc[k];

                        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1){
                            int node = nrow*n + ncol;
                            s.insert(ds.findParent(node));
                        }
                    } 
                    int sum = 0;
                    for(auto it : s){
                        sum += ds.size[it];
                    }
                    mx = max(sum+1, mx);
                }
            }
        }

        return mx != INT_MIN ? mx : n*n;
    }
};


/*


1 0
0 1


*/