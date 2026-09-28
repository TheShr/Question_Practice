class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        if(grid[0][0] == 1) return -1;
        // {{dist, {x, y}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        int dr[] = {0, 0, 1, -1, 1, 1, -1, -1};
        int dc[] = {1, -1, 0, 0, 1, -1, 1, -1};

        pq.push({1, {0,0}});
        dist[0][0] = 1;
        while(!pq.empty()){
            auto &it = pq.top();
            int d = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();

            for(int k = 0; k<8; k++){
                int nrow = row + dr[k];
                int ncol = col + dc[k];

                if(ncol < m && ncol >=0 && nrow < n && nrow >= 0 && grid[nrow][ncol] == 0){
                    if(dist[nrow][ncol] > d + 1){
                        dist[nrow][ncol] = d + 1;
                        pq.push({dist[nrow][ncol], {nrow, ncol}});
                    }
                }
                
            }
        }return dist[n-1][m-1] != INT_MAX ? dist[n-1][m-1] : -1;
    }
};