class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<pair<int, int>, int>> q;

        int tm = 0, t = 0, cnt1 = 0, cnt2 = 0;
      
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i,j}, 0});
                    
                }else vis[i][j] = 0;
                
                if(grid[i][j] == 1) cnt1++;
            }
        }
        int dr[] = {-1 , 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            t = q.front().second;
            q.pop();
            tm = max(t, tm);
            for(int k = 0; k<4; k++){
                    int nrow = row + dr[k];
                    int ncol = col + dc[k];

                    if(nrow >= 0 && nrow < n && ncol >= 0 &&  ncol < m && grid[nrow][ncol] == 1
                    && !vis[nrow][ncol]){
                            vis[nrow][ncol] = 2;
                            cnt2++;
                            q.push({{nrow, ncol}, t+1});
                    }
                
            }
        }

        if(cnt1 != cnt2) return -1;
        else return tm;
    
    }
};