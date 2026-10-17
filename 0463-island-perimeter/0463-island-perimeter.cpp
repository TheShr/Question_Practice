class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n , vector<int> (m , 0));
        int ans = 0;
        queue<pair<int, int>> q;
        int dr[] = {1, -1 , 0 , 0};
        int dc[] = {0, 0, -1, 1};
        for(int i = 0; i<n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                     q.push({i,j});
                     vis[i][j] = 1;
                     break;
                }
            }
            if(!q.empty()) break;
        }
         while(!q.empty()){
                            auto it = q.front();
                            int r = it.first;
                            int c = it.second;

                            q.pop();
                            int cnt = 4;
                            for(int k = 0; k<4; k++){
                                int nrow = r + dr[k];
                                int ncol = c + dc[k];
                                
                                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                                   grid[nrow][ncol] == 1 && !vis[nrow][ncol]
                                ){
                                    
                                    vis[nrow][ncol] = 1;
                                    q.push({nrow, ncol});
                                }
                                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                                   grid[nrow][ncol] == 1
                                ){
                                    cnt--;
                                }
                            }
                            ans += cnt;
                        }

        return ans;
    }
};