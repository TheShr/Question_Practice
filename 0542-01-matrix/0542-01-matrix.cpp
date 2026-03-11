class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>> q;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dis(n, vector<int> (m, 0));
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }

        int drow[] = {-1 , 0, +1, 0};
        int dcol[] = {0 , 1 , 0 , -1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            dis[r][c] = steps;
            q.pop();
            for(int i = 0 ; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol}, steps+1});
                    //dis[r][c] = steps;

                }
            }
        }
        return dis;
    
    }
};