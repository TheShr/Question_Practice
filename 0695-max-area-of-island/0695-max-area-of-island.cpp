class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;

        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<int , int>> q;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vis[i][j] = 1;
                    q.push({i,j});

                    int dr[] = {0 , 0, -1, 1};
                    int dc[] = {-1 , 1, 0, 0};

                    int area = 0;
                    while(!q.empty()){
                        auto &it = q.front();
                
                        int r = it.first;
                        int c = it.second;
                        q.pop();
                        area++;

                        for(int k = 0 ; k<4; k++){
                            int nrow = r + dr[k];
                            int ncol = c + dc[k];

                            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                                vis[nrow][ncol] = 1;
                                q.push({nrow, ncol});
                            }
                        }
                    }
                    ans = max(area, ans);
                }
            }
        }

        
        return ans;
    }
};