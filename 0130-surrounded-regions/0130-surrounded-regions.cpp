class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));
        queue<pair<int, int>> q;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                   if(!vis[i][j] && board[i][j] == 'O'){
                        vis[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
        }

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            

            for(int k = 0; k<4; k++){
                int nrow = row + dr[k];
                int ncol = col + dc[k];

                if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }

        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(vis[i][j] == 0) board[i][j] = 'X';
            }
        }
        
    }
};