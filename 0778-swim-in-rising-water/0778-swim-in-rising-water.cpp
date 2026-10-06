class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int dr[] = {0 ,0, -1, 1};
        int dc[] = {-1 , 1, 0, 0};
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
         priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > q;

        q.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];

        while(!q.empty()){
            auto &it = q.top();
            int effort = it.first;
           
            int r = it.second.first;
            int c = it.second.second;

            q.pop();
            //if(dist[r][c] == INT_MAX) return -1;
            for(int k = 0; k<4; k++){
                int nrow = r + dr[k];
                int ncol = c + dc[k];
                //int w = grid[r][c];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n){
                    int newEffort = max(effort, grid[nrow][ncol]);
                    if(dist[nrow][ncol] > newEffort ){
                        dist[nrow][ncol] = newEffort;

                        q.push({newEffort, {nrow, ncol}});

                    }
                }
            }

            
        }return dist[n-1][n-1];
    }
};