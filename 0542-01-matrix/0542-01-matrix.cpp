class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));
        vector<vector<int>> ans(m, vector<int> (n, 0));

        

        queue<pair<pair<int, int>, int>> q;

        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j] == 0 && !vis[i][j])  q.push({{i,j}, 0});
            }
        }
       

        int dr[] = {0 ,0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            ans[row][col] = dist;
            
            q.pop();
            
            for(int k = 0; k<4; k++){
                int nrow = row + dr[k];
                int ncol = col + dc[k];
                if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && !vis[nrow][ncol] && mat[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, dist+1});
                }
                
            }

        }
        return ans;
    }
};