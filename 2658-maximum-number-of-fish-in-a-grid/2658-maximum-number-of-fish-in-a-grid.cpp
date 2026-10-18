class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));

        int dr[] = {0, 0, -1 ,1};
        int dc[] = {-1, 1, 0, 0};

        int ans = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] > 0){
                    q.push({i, j});
                    vis[i][j] = 1;
                    int d = 0;

                    while(!q.empty()){
                            auto it = q.front();
                            int r = it.first;
                            int c = it.second;

                            q.pop();
                            d += grid[r][c];

                            for(int k = 0; k < 4; k++){
                                int nrow = r + dr[k];
                                int ncol = c + dc[k];

                                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                                   && grid[nrow][ncol] > 0 && !vis[nrow][ncol]){
                                    vis[nrow][ncol] = 1;
                                    q.push({nrow, ncol});
                                }
                            }
                    }
                    ans = max(d , ans);
                }
            }
        }

        return ans;
    }
};