class Solution {
public:
    void bfs(vector<vector<int>>& ans, vector<vector<int>>& vis, vector<vector<int>>& image, int sr, int sc, int color){
        vis[sr][sc] = 1;
        ans[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;

        q.push({sr,sc});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k = 0; k<4; k++){
                int nrow = row + dr[k];
                int ncol = col + dc[k];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == image[sr][sc] && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    ans[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        if(image.empty() || image[0].empty()) return image;
        if(color == image[sr][sc]) return image;

        vector<vector<int>> ans = image;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        //ans = image;

        bfs(ans, vis, image, sr, sc, color);
        return ans;
    }
};