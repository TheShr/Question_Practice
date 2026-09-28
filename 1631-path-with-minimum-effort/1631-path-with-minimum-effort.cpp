class Solution {
public:
    // we have to look for minimun (maximum abs diff)
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        
        // {{effort, {x, y}}
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        pq.push({0, {0,0}});
        dist[0][0] = 0;
        while(!pq.empty()){
            auto &it = pq.top();
            int effort = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();

            for(int k = 0; k<4; k++){
                int nrow = row + dr[k];
                int ncol = col + dc[k];

                if(ncol < m && ncol >=0 && nrow < n && nrow >= 0){
                    int newEffort = max(effort, abs(grid[row][col] - grid[nrow][ncol]));
                    if(dist[nrow][ncol] > newEffort ){
                        dist[nrow][ncol] = newEffort;

                        pq.push({newEffort, {nrow, ncol}});

                    }
                }
                
            }
        }return dist[n-1][m-1];
    }
};